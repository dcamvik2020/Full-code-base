/*
 * formatter.c
 *
 *  Created on: 30.07.2013
 *  Reincarnated on: 05.08.2014 - 9.11.2014; 1.10.2015 - 6.10.2015; 13.01.2019 - 3.02.2019
 *      Author: Andrey Tretyakov (MIPT)
 *      Copyright © All Rights Reserved
 */

#include <stdio.h>
#include <string.h>

//#define CONTEST

#define min(a, b) ((a) < (b) ? (a) : (b))

void strdel(char *s, unsigned int idx, unsigned int count);
int strins(char *t, unsigned int size, const char *s, unsigned int idx);
char **read_file(FILE *fInput, int *num_lines);
void free_data(char *Data[], int n);
int fexists(const char *filename);

//HELPER FUNCTIONS

double count_indents(const char *s, const char *indent) {
	double n;
	int i, len = strlen(indent);
	if (len == 0)
		return 0;
	//int part of count
	for (n = 0; strncmp(s + (int)n * len, indent, len) == 0; n++);
	//fraq part of count
	for (i = 0; i < len && s[(int)n*len+i] == indent[i]; i++);
	return n + i / (double)len;
}

void show_whitespaces(char *buf, unsigned int nbuf) {
	char *s;
	int i;
	while ((s = strchr(buf, '\t')) != NULL && strlen(buf) + 4 < nbuf) {
		strdel(buf, s - buf, 1);
		strins(buf, nbuf, "<TAB>", s - buf);
	}
	for (i = 0; buf[i]; i++)
		if (buf[i] == ' ')
			buf[i] = '.';
}

char *surround_text(char *buf, int nbuf, const char *s, int idx) {
	int i1, i2, i3, i4;
	if (!buf || !s || nbuf < 8)
		return NULL;
	//seek left side
	for (i1 = idx; i1 > 0 && (s[i1] == ' ' || s[i1] == '\t'); i1--);
	for ( ; i1 >= 0 && s[i1] != ' ' && s[i1] != '\t'; i1--);
	i1++;
	//seek right side
	for (i2 = idx; s[i2] == ' ' || s[i2] == '\t'; i2++);
	for ( ; s[i2] && s[i2] != ' ' && s[i2] != '\t'; i2++);
	//copy to buffer
	buf[0] = '\0';
	if (i2 - i1 < nbuf)
		strncat(buf, s + i1, i2 - i1);
	else {
		i3 = idx - (nbuf - 1) / 2;
		i4 = idx + (nbuf - 1) / 2 + 1;
		if (i1 >= i3)
			strncat(buf, s + i1, nbuf - 1); else
		if (i2 <= i4)
			strncat(buf, s + i2 - (nbuf - 1), nbuf - 1);
		else
			strncat(buf, s + i3, nbuf - 1);
		if (i1 < i3) {
			buf[0] = '.'; buf[1] = '.'; buf[2] = '.';
		}
		if (i2 > i4) {
			buf[nbuf-4] = '.'; buf[nbuf-3] = '.'; buf[nbuf-2] = '.';
		}
	}
	return buf;
}

//s is parsed line
//i is index of current symbol in this line

int begin_of_code(const char *s, int i) {
	//seek previous text
	for (i = i - 1; i >= 0 && (s[i] == ' ' || s[i] == '\t'); i--);
	return i < 0;
}

//pass "s + idx", please
int end_of_code(const char *s) {
/*	int i, j;
	//delete duplicating whitespaces
	for (i = j = 0; s[j]; i++, j++) {
		if (s[j] == '\t')
			s[j] = ' ';
		if (s[j] == ' ' && (s[j+1] == ' ' || s[j+1] == '\t'))
			i--;
		else
			s[i] = s[j];
	}
	s[i] = '\0';*/
	int i;
	for (i = 0; s[i] == ' ' || s[i] == '\t'; i++);
	if (!s[i])
		return 1;
	if (s[i] == '/' && s[i+1] == '/')
		return 1;
	if (s[i] == '/' && s[i+1] == '*') {
		for (i = i + 2; s[i]; i++)
			if (s[i] == '*' && s[i+1] == '/') {
				i += 2;
				break;
			}
		if (!s[i])
			return 1;
	}
	return 0;
}

int is_ident_char(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_';
}

//not only identifier, but numeric constants as well
char *get_identifier(char *buf, int nbuf, const char *s, int i) {
	int j;
	//seek the beginning of identifier
	if (is_ident_char(s[i])) {
		for ( ; i >= 0 && is_ident_char(s[i]); i--);
		i++;
	}
	//seek the end of identifier
	for (j = i; is_ident_char(s[j]); j++);
	//strncpy max i-idx chars if any
	buf[0] = '\0'; strncat(buf, s + i, min(j - i, nbuf - 1));
	return buf;
}

//pass "s + i", please
char *get_lexeme(char *buf, int nbuf, const char *s) {
	int len;
	for ( ; *s == ' ' || *s == '\t'; s++); //skip spaces and TABs
	if (!s[0])
		return NULL;
	//identifiers
	if (is_ident_char(s[0]))
		return get_identifier(buf, nbuf, s, 0);
	//else - one symbol
	len = 1;
	//operators
	//  <<=  >>=
	if ((s[0] == '<' || s[0] == '>') && s[0] == s[1] && s[2] == '=')
		len = 3; else
	//  ...
	if (s[0] == '.' && s[1] == s[0] && s[2] == s[1])
		len = 3; else
	//  ==  !=  <=  >=  +=  -=  *=  /=  %=  &=  |=  ^=
	if ((s[0] == '=' || s[0] == '!' || s[0] == '<' || s[0] == '>' ||
		 s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/' || s[0] == '%' ||
		 s[0] == '&' || s[0] == '|' || s[0] == '^') && s[1] == '=')
		len = 2; else
	//  ==  ++  --  &&  ||  <<  >>  ::
	if ((/*s[0] == '=' ||*/ s[0] == '+' || s[0] == '-' || s[0] == '&' || s[0] == '|' ||
		 s[0] == '<' || s[0] == '>' || s[0] == ':') && s[0] == s[1])
		len = 2; else
	//  ->  //  /*  */
	if ((s[0] == '-' && s[1] == '>') || (s[0] == '/' && s[1] == '/') ||
		 (s[0] == '/' && s[1] == '*') || (s[0] == '*' && s[1] == '/'))
		len = 2; else
	//  \\  \"  \'  \?  \n  \r  \t  \v  \f  \b  \a
	if (s[0] == '\\' && (s[1] == '\\' || s[1] == '"' || s[1] == '\'' || s[1] == '?' ||
		 s[1] == 'n' || s[1] == 'r' || s[1] == 't' || s[1] == 'v' || s[1] == 'f' || s[1] == 'b' || s[1] == 'a'))
		len = 2; else
	//  \0  ... all octals
	if (s[0] == '\\' && s[1] >= '0' && s[1] <= '7')
		while (s[len] >= '0' && s[len] <= '7')
			len++;
	else
	//  \x12ab  ... all hexadecimals
	if (s[0] == '\\' && s[1] == 'x') {
		len++;
		while ((s[len] >= '0' && s[len] <= '9') || (s[len] >= 'a' && s[len] <= 'f') || (s[len] >= 'A' && s[len] <= 'F'))
			len++;
	}
	//strncpy max i-idx chars if any
	buf[0] = '\0'; strncat(buf, s, min(len, nbuf - 1));
	return buf;
}

char *get_next_token(char *buf, int nbuf, const char *s, int i, int *pline, const char **ps);

enum Statement {UNKNOWN, IF, ELSE, FOR, WHILE, SWITCH, DO, ENUM, STRUCT, UNION, CLASS, FUNC, BLOCK};

const char *get_statement_name(enum Statement statement) {
	switch (statement) {
		case IF:
			return "if";
		case ELSE:
			return "else";
		case FOR:
			return "for";
		case WHILE:
			return "while";
		case SWITCH:
			return "switch";
		case DO:
			return "do";
		case ENUM:
			return "enum";
		case STRUCT:
			return "struct";
		case UNION:
			return "union";
		case CLASS:
			return "class";
		default:
			return "?";
	}
}

enum Statement get_statement(const char *statement) {
	if (!strcmp(statement, "if"))
		return IF;
	if (!strcmp(statement, "else"))
		return ELSE;
	if (!strcmp(statement, "for"))
		return FOR;
	if (!strcmp(statement, "while"))
		return WHILE;
	if (!strcmp(statement, "switch"))
		return SWITCH;
	if (!strcmp(statement, "do"))
		return DO;
	if (!strcmp(statement, "enum"))
		return ENUM;
	if (!strcmp(statement, "struct"))
		return STRUCT;
	if (!strcmp(statement, "union"))
		return UNION;
	if (!strcmp(statement, "class"))
		return CLASS;
	return UNKNOWN;
}

enum Keyword {UNKNOWN0, CASE, DEFAULT, PUBLIC, PROTECTED, PRIVATE};

/*const char *get_keyword_name(enum Keyword keyword) {
	switch (keyword) {
		case CASE:
			return "case";
		case DEFAULT:
			return "default";
		case PUBLIC:
			return "public";
		case PROTECTED:
			return "protected";
		case PRIVATE:
			return "private";
		default:
			return "?";
	}
}*/

enum Keyword get_keyword(const char *keyword) {
	if (!strcmp(keyword, "case"))
		return CASE;
	if (!strcmp(keyword, "default"))
		return DEFAULT;
	if (!strcmp(keyword, "public"))
		return PUBLIC;
	if (!strcmp(keyword, "protected"))
		return PROTECTED;
	if (!strcmp(keyword, "private"))
		return PRIVATE;
	return UNKNOWN0;
}

int begin_of_statement(const char *prev_lex) {
	return prev_lex[0] == ';' || prev_lex[0] == '}' || prev_lex[0] == '{' || !prev_lex[0];
}

//NO COMMENTS

#define MAX_LINE_LEN 4096
#define NSTACK 1024
#define MAX_LEX_LEN 256
#define SUR_TXT_LEN 20

int line = 0;
int bracend = -1;
int bFunc = 0;

int errors = 0;
int warnings = 0;

//FILE *fTokens2;

int parse_line(char *buf, int nbuf);

int line_break(char *s, int nbuf, int i, int level, const char *indent, enum Statement oper) {
	char txt[SUR_TXT_LEN], lex[MAX_LEX_LEN];
	int j;
	if (oper == UNKNOWN)
		printf("%d: \"%s\" must be on a new line: \"%s\"\n", line + 1, get_lexeme(lex, sizeof lex, s + i), surround_text(txt, sizeof txt, s, i));
	else
		printf("%d: The body of \"%s\" %s must be on a new line: \"%s\"\n", line + 1,
				get_statement_name(oper), oper != ELSE ? "statement" : "branch", surround_text(txt, sizeof txt, s, i));
	//delete whitespaces before s[i]
	for ( ; i > 0 && (s[i-1] == ' ' || s[i-1] == '\t'); i--);
	//delete whitespaces after s[i]
	for (j = i; s[j] == ' ' || s[j] == '\t'; j++);
	strdel(s, i, j - i);
	//insert line-break
	if (strins(s, nbuf, "\n", i) < 0)
		return -1;
	i++;
	//insert indents
	if (s[i] == '}')
		level--;
	for (j = 0; j < level; j++)
		if (strins(s, nbuf, indent, i) < 0)
			return -1;
	return parse_line(s + i, nbuf - i); //recursion!
}

typedef struct {
	enum Statement oper;
	int level; //saved level before this operator
	char brace; //'{', '-' or '?'
} Level;

int catch_else(char *s, int i, Level stack[], int *pst, int *plevel) {
	char next_lex[MAX_LEX_LEN];
	if (get_next_token(next_lex, sizeof next_lex, s, i + 1, NULL, NULL) && !strcmp(next_lex, "else")) {
		int st = *pst, level = *plevel, unwind = 1;
		if (st <= 0)
			return -1;
		//unwind all operators not related to this "else"
		while (st > 0 && stack[st-1].oper != IF) {
			level = stack[st-1].level; //level--;
			st--;
			unwind++;
		}
		if (st <= 0) // || stack[st-1].oper != IF
			return -1;
		//move "else" left
		level = stack[st-1].level; //level--;
		//don't st-- !
		*pst = st; *plevel = level;
		return unwind;
	}
	return 0;
}

int parse_line(char *buf, int nbuf) {
	static char indent[1024] = "";
	static Level stack[NSTACK];
	static int level = 0, st = 0;
	static int parentheses = 0, brackets = 0, saved_parens;
	static char state = '\0';
	static char state_sw = '\0';
	static int state_ter = 0;
	static int isComment1 = 0, isComment2 = 0, isMacro = 0;
	static char isString = '\0';
	static int isInitializator = 0;
	static char prev_lex[MAX_LEX_LEN] = "";
	static int excuse_indent = 0;
	char txt[SUR_TXT_LEN], lex[MAX_LEX_LEN], next_lex[MAX_LEX_LEN], *s;
	enum Keyword keyword;
	int i, j;
	int hasSpace = 0, hasTab = 0;
	s = buf;
	if (bFunc && level == 0) {
		indent[0] = '\0';
		bracend = -1;
	}
	//skip empty string
	if (!s[0]) {
		isComment1 = isMacro = 0;
		return 0;
	}
	//omit trailing whitespaces
	for (i = strlen(s) - 1; i >= 0 && (s[i] == ' ' || s[i] == '\t'); i--);
	if (i >= 0 && s[i+1]) {
		s[i+1] = '\0';
		printf("%d: Warning: Trailing whitespaces\n", line + 1);
		warnings++;
	}
	//omit leading whitespaces
	for (i = 0; s[i] == ' ' || s[i] == '\t'; i++)
		if (s[i] == ' ')
			hasSpace = 1;
		else
			hasTab = 1;
	if (hasSpace && hasTab && parentheses == 0 && brackets == 0 && isInitializator == 0 && !isString) {
		printf("%d:%s Mixing Spaces and TABs\n", line + 1, s[i] ? "" : " Warning:");
		if (s[i])
			errors += 10; //1
		else
			warnings++;
	}

	//COMMENTS and MULTI-LINES
	//skip multi-line comments
	if (isComment1) {
		if (s[strlen(s)-1] != '\\')
			isComment1 = 0;
		return 0;
	}
	if (isComment2) {
		//seek end of comment
		for ( ; s[i]; i++)
			if (s[i] == '*' && s[i+1] == '/')
				break;
		if (!s[i]) //not found
			return 0;
		isComment2 = 0; //found
		i += 2;
		if (!s[i])
			return 0;
		else {
			printf("%d: Warning: Text after multi-line comment:\n", line + 1);
			warnings++;
			return line_break(s, nbuf, i, level, indent, UNKNOWN); //recursion!
		}
	}
	//handle preprocessor directives
	if (s[i] == '#' && !isString) {
		if (i > 0) {
			printf("%d: Warning: Whitespaces before preprocessor directive: \"%s\"\n", line + 1, surround_text(txt, sizeof txt, s, i));
			warnings++;
			strdel(s, 0, i);
		}
		isMacro = 1;
	}
	if (isMacro) {
		if (s[strlen(s)-1] != '\\')
			isMacro = 0;
		return 0;
	}

	//INDENTS
	if (!isMacro && !isString && !isComment1 && !isComment2 && !(s[0] == '/' && (s[1] == '/' || s[1] == '*')) &&
		parentheses == 0 && brackets == 0 && isInitializator == 0) {
		char tbuf[MAX_LINE_LEN], tbuf_ex[MAX_LINE_LEN];
		int ind = level;
		//if '}' then indent = "level-1"
		if (s[i] == '}') {
			if (st <= 0)
				return -1;
			ind = stack[st-1].level; //ind--;
		} else
		if (get_lexeme(next_lex, sizeof next_lex, s + i) && //on this particular line
			((keyword = get_keyword(next_lex)) == CASE || keyword == DEFAULT ||
			keyword == PUBLIC || keyword == PROTECTED || keyword == PRIVATE) &&
			(keyword == CASE ||
			(get_next_token(next_lex, sizeof next_lex, s, i + strlen(next_lex), NULL, NULL) && !strcmp(next_lex, ":"))))
			ind--;
		//define indent (for the first time)
		if (ind == 1 && !indent[0]) {
//			strncpy(indent, s, min(i, sizeof indent - 1)); indent[min(i, sizeof indent - 1)] = '\0';
			/*indent[0] = '\0';*/ strncat(indent, s, min(i, (int)sizeof indent - 1));
			if (!indent[0] || (hasSpace && hasTab)) {
				indent[0] = '\t'; indent[1] = '\0';
				hasSpace = 0; hasTab = 1;
			} else
			//check that if spaces, that indent is 2^n spaces (n > 0)
			if (hasSpace) {
				j = strlen(indent);
				while (j % 2 == 0)
					j /= 2;
				if (j != 1 || strlen(indent) == 1) {
					strcpy(tbuf, indent);
					show_whitespaces(tbuf, sizeof tbuf);
					printf("%d:%s Wrong indent \"%s\": not 2, 4, 8, ..., 2^n spaces\n", line + 1, s[i] ? "" : " Warning:", tbuf);
					if (s[i])
						errors += 10; //1
					else
						warnings++;
					strcpy(indent, "    ");
				}
			}
		}
		//make correct indent * level
		tbuf[0] = '\0'; tbuf_ex[0] = '\0';
		for (j = 0; j < ind; j++) {
			if (strlen(tbuf) + strlen(indent) >= sizeof tbuf)
				return -1;
			strcat(tbuf, indent);
		}
		//append one more character (for correct comparing)
		if (strlen(tbuf) + 1 >= sizeof tbuf)
			return -1;
		tbuf[strlen(tbuf)+1] = '\0'; tbuf[strlen(tbuf)] = s[i];
		//excuse indent
		if (excuse_indent != 0 && indent[0]) {
			for (j = 0; j < ind + excuse_indent; j++) {
				if (strlen(tbuf_ex) + strlen(indent) >= sizeof tbuf_ex)
					return -1;
				strcat(tbuf_ex, indent);
			}
			if (strlen(tbuf_ex) + 1 >= sizeof tbuf_ex)
				return -1;
			tbuf_ex[strlen(tbuf_ex)+1] = '\0'; tbuf_ex[strlen(tbuf_ex)] = s[i];
			if (strncmp(s, tbuf_ex, i + 1) == 0)
				level += excuse_indent;
			excuse_indent = 0;
		} else
			strcpy(tbuf_ex, tbuf);
		//compare indents
		if (strncmp(s, tbuf, i + 1) != 0 && strncmp(s, tbuf_ex, i + 1) != 0) {
			char tbuf1[sizeof tbuf], tbuf2[sizeof indent];
			double ind2;
			//remove appended excess character
			if (s[i] && tbuf[0])
				tbuf[strlen(tbuf)-1] = '\0';
			strncpy(tbuf1, s, i); tbuf1[i] = '\0';
			ind2 = count_indents(tbuf1, indent);
			show_whitespaces(tbuf1, sizeof tbuf1);
			strcpy(tbuf2, tbuf);
			show_whitespaces(tbuf2, sizeof tbuf2);
			printf("%d:%s Wrong indent: should be \"%s\" (%d indents) instead of \"%s\" (%lg indents)\n", line + 1, s[i] ? "" : " Warning:", tbuf2, ind, tbuf1, ind2);
			if (s[i])
				errors += 10; //1
			else
				warnings++;
			//fix indents
			strdel(s, 0, i);
			if (strins(s, nbuf, tbuf, 0) < 0)
				return -1;
		}
		//omit leading whitespaces
		for (i = 0; s[i] == ' ' || s[i] == '\t'; i++);
	}

//	fprintf(fTokens2, "%s\n", s);
	//MAIN PARSE
	// for ( ; s[i]; i++)
	for (lex[0] = '\0';
		get_lexeme(lex, sizeof lex, s + i);
		i += strlen(lex), strcpy(prev_lex, lex)) {

		for ( ; s[i] == ' ' || s[i] == '\t'; i++); //workaround

		if (s[i] == '\r') {
			s[i] = '.';
			printf("%d: CR ('\\r') detected in the middle of the line: \"%s\"\n", line + 1, surround_text(txt, sizeof txt, s, i > 0 ? i - 1 : i));
			//Use Linux (LF, '\\n') or Windows (CRLF, '\\r\\n') line separator\n
			errors += 10; //1
			s[i] = '\n';
			return parse_line(s + i + 1, nbuf - i - 1); //recursion!
		}

		if (isString) {
			if (s[i] == isString)
				isString = '\0';
			continue;
		}

//		fprintf(fTokens2, "%s\n", lex);
		if (s[i] == '/' && s[i+1] == '/') { // "//"
			if (s[strlen(s)-1] == '\\')
				isComment1 = 1;
			break;
		}

		if (s[i] == '/' && s[i+1] == '*') { // "/*"
			for (i = i + 2; s[i] && !(s[i] == '*' && s[i+1] == '/'); i++); // "*/"
			if (!s[i]) {
				isComment2 = 1;
				break;
			}
			strcpy(lex, prev_lex); //don't copy "/*" to prev_lex
			i = i + 2 - strlen(lex); //workaround: add 2 (strlen("/*") == strlen("*/")); strlen(lex) will be added back later in FOR
		} else

		if (s[i] == '"' || s[i] == '\'')
			isString = s[i]; else

		if (s[i] == '{') {
			if (!strcmp(prev_lex, "=") || isInitializator)
				isInitializator++;
			if (isInitializator)
				continue;
			//compound statement (block) must be from new line
			if (begin_of_statement(prev_lex) && !begin_of_code(s, i)) {
				errors += 10; //1
				return line_break(s, nbuf, i, level, indent, UNKNOWN); //recursion!
			}
			//define style of open braces (for the first time)
			if (bracend == -1) {
				//seek previous text
				for (j = i - 1; j >= 0 && (s[j] == ' ' || s[j] == '\t'); j--);
				if (j >= 0)
					bracend = 1;
				else
					bracend = 0;
			}
			//before "{"
			//must be operator's header or signature
			if (bracend == 1)
				//space
				if (i > 0 && s[i-1] != ' ' && s[i-1] != '\t') {
					printf("%d: No space before \"{\": \"%s\"\n", line + 1, surround_text(txt, sizeof txt, s, i));
					errors += 3; //3
					if (strins(s, nbuf, " ", i) < 0)
						return -1;
					i++;
				}
			//no, must be indent only
			if (bracend == 0)
				if (!begin_of_code(s, i) && !(!strcmp(prev_lex, "else") &&
					get_lexeme(next_lex, sizeof next_lex, s) && next_lex[0] == '}') /*not "} else {"*/) {
					errors += 3; //3
					return line_break(s, nbuf, i, level, indent, UNKNOWN); //recursion!
				}
			//determine, operator or function connected to this "{"
			if (!(st > 0 && stack[st-1].brace == '?' /*last operator was marked to determine the brace*/)) {
				//add new level
				if (st >= NSTACK)
					return -1;
				st++;
				if (prev_lex[0] == ')')
					stack[st-1].oper = FUNC;
				else if (begin_of_statement(prev_lex))
					stack[st-1].oper = BLOCK;
				else
					stack[st-1].oper = UNKNOWN; //perhaps, function or method
			}
			stack[st-1].level = level;
			stack[st-1].brace = '{';
			level++;
			//switch, class (+ struct) public, protected, private support
			if (st > 0 && (stack[st-1].oper == SWITCH || ((stack[st-1].oper == CLASS || stack[st-1].oper == STRUCT) &&
				//after class or struct is public, protected or private
				get_next_token(next_lex, sizeof next_lex, s, i + 1, NULL, NULL) &&
				((keyword = get_keyword(next_lex)) == CASE || keyword == DEFAULT ||
				keyword == PUBLIC || keyword == PROTECTED || keyword == PRIVATE))))
				excuse_indent = 1;
			//after "{"
			if (!end_of_code(s + i + 1) && !(st > 0 && stack[st-1].oper == ENUM)) {
				errors += 10; //1
				strcpy(prev_lex, lex);
				return line_break(s, nbuf, i + 1, level, indent, UNKNOWN); //recursion!
			}
		} else

		if (s[i] == '}') {
			int bElse;
			if (isInitializator) {
				isInitializator--;
				continue;
			}
			//before "}"
			if (!begin_of_code(s, i) && !(st > 0 && stack[st-1].oper == ENUM)) {
				errors += 10; //1
				return line_break(s, nbuf, i, level, indent, UNKNOWN); //recursion!
			}
			//catch "else" branch
			if ((bElse = catch_else(s, i, stack, &st, &level)) == -1)
				return -1;
			//do, struct, union, class, enum support
			if (st > 0 && (stack[st-1].oper == DO || stack[st-1].oper == STRUCT || stack[st-1].oper == UNION || stack[st-1].oper == CLASS || stack[st-1].oper == ENUM)) {
				level = stack[st-1].level; //level--;
				stack[st-1].brace = '-';
			} else {
				//other
				if (!bElse) {
					if (st <= 0)
						return -1;
					stack[st-1].brace = '-'; //erase "}" from stack to unwind it correctly up to next "}" (while must do at least one iteration)
					while (st > 0 && stack[st-1].brace == '-') { //unwind stack until next "{"
						level = stack[st-1].level; //level--;
						st--;
					}
				}
				//after "}"
				if (bElse != 1 && !end_of_code(s + i + 1)) {
					errors += 10; //1
					strcpy(prev_lex, lex);
					return line_break(s, nbuf, i + 1, level, indent, UNKNOWN); //recursion!
				}
			}
			//if we decide not no break line, then check for space
			if (s[i+1] && s[i+1] != ' ' && s[i+1] != '\t' && s[i+1] != ';') {
				printf("%d: No space after \"%c\": \"%s\"\n", line + 1, s[i], surround_text(txt, sizeof txt, s, i));
				errors += 3; //3
				if (strins(s, nbuf, " ", i + 1) < 0)
					return -1;
			}
		} else

		if (s[i] == '(') {
			if (state == 'k') {
				state = 'c'; //Condition part of the statement was reached
				saved_parens = parentheses;
			}
			parentheses++;
		} else

		if (s[i] == ')') {
			parentheses--;
			if (parentheses < 0)
				return -1;
			//if we've processed statement's header
			if (state == 'c' && parentheses == saved_parens) {
				state = 's'; //now begins Statement
				if (get_next_token(next_lex, sizeof next_lex, s, i + 1, NULL, NULL) && next_lex[0] != '{') {
					if (st <= 0 || stack[st-1].brace != '?')
						return -1;
					stack[st-1].brace = '-';
					level++;
					if (!end_of_code(s + i + 1) && next_lex[0] != ';') {
						errors += 4; //2
						strcpy(prev_lex, lex);
						return line_break(s, nbuf, i + 1, level, indent, stack[st-1].oper); //recursion!
					}
				}
			}
		} else

		if (s[i] == '[') {
			brackets++;
		} else

		if (s[i] == ']') {
			brackets--;
			if (brackets < 0)
				return -1;
		} else

		if (s[i] == ';') {
			if (state != 'c') { //not in for ( ; ; )
				int bElse, unwind = 0;
				//catch "else" branch
				if ((bElse = catch_else(s, i, stack, &st, &level)) == -1)
					return -1;
				//struct, union, class, enum support
				if (st > 0 && stack[st-1].brace == '?' &&
					(stack[st-1].oper == STRUCT || stack[st-1].oper == UNION || stack[st-1].oper == CLASS || stack[st-1].oper == ENUM))
					stack[st-1].brace = '-';
				//other
				if (!bElse)
					while (st > 0 && stack[st-1].brace == '-') { //unwind stack until next "{"
						level = stack[st-1].level; //level--;
						st--;
						unwind++;
					}
				if ((bElse > 1 || (bElse == 0 && unwind)) && !end_of_code(s + i + 1)) {
					errors += 10; //1
					strcpy(prev_lex, lex);
					return line_break(s, nbuf, i + 1, level, indent, UNKNOWN); //recursion!
				}
			}
			//Whitespaces
			if (s[i+1] && s[i+1] != ' ' && s[i+1] != '\t' && s[i+1] != '}') {
				printf("%d: No space after \"%c\": \"%s\"\n", line + 1, s[i], surround_text(txt, sizeof txt, s, i));
				errors += 10; //1
				if (strins(s, nbuf, " ", i + 1) < 0)
					return -1;
			}
		} else

		if (s[i] == ':' && s[i+1] != ':' && (state_sw == 'c' || (keyword = get_keyword(prev_lex)) == DEFAULT ||
			keyword == PUBLIC || keyword == PROTECTED || keyword == PRIVATE)) {
			state_sw = '\0';
			if (!end_of_code(s + i + 1)) {
				errors += 10; //1
				strcpy(prev_lex, lex);
				return line_break(s, nbuf, i + 1, level, indent, UNKNOWN); //recursion!
			}
		} else {

			//LEXEMES
			enum Statement oper;
			//Whitespaces
			if (s[i] == ',' && s[i+1] && s[i+1] != ' ' && s[i+1] != '\t') {
				printf("%d: No space after \"%c\": \"%s\"\n", line + 1, s[i], surround_text(txt, sizeof txt, s, i));
				errors += 4; //2
				if (strins(s, nbuf, " ", i + 1) < 0)
					return -1;
			}
			//operators
			if (brackets == 0) {
				if (!strcmp(lex, "+=") || !strcmp(lex, "-=") || !strcmp(lex, "*=") || !strcmp(lex, "/=") || !strcmp(lex, "%=") ||
					!strcmp(lex, "&=") || !strcmp(lex, "|=") || !strcmp(lex, "^=") || !strcmp(lex, "<<=") || !strcmp(lex, ">>=") ||
					!strcmp(lex, "?") || (!strcmp(lex, ":") && state_ter > 0) || !strcmp(lex, "=") ||
					!strcmp(lex, "&&") || !strcmp(lex, "||") || !strcmp(lex, "|") || !strcmp(lex, "^") ||
					!strcmp(lex, "==") || !strcmp(lex, "!=") ||
					!strcmp(lex, ">=") || !strcmp(lex, "<=") || ((!strcmp(lex, ">") || !strcmp(lex, "<")) && (parentheses > 0)) ||
					!strcmp(lex, "<<") || !strcmp(lex, ">>") ||
					!strcmp(lex, "%")) {
					int b1 = 0, b2 = 0;
					j = strlen(lex);
					if (i > 0 && s[i-1] != ' ' && s[i-1] != '\t')
						b1 = 1;
					if (s[i+j] && s[i+j] != ' ' && s[i+j] != '\t')
						b2 = 1;
					if (b1 || b2) {
						printf("%d: Must be spaces around binary operator \"%s\": \"%s\"\n", line + 1, lex, surround_text(txt, sizeof txt, s, i));
						errors += 3; //3
					}
					if (b1) {
						if (strins(s, nbuf, " ", i) < 0)
							return -1;
						i++;
					}
					if (b2)
						if (strins(s, nbuf, " ", i + j) < 0)
							return -1;
					if (lex[0] == '?')
						state_ter++; else
					if (state_ter > 0 && !strcmp(lex, ":"))
						state_ter--;
				} else
				if (!strcmp(lex, ":") && s[i+1] && s[i+1] != ' ' && s[i+1] != '\t') {
					printf("%d: No space after \"%c\": \"%s\"\n", line + 1, s[i], surround_text(txt, sizeof txt, s, i));
					errors += 3; //3
					if (strins(s, nbuf, " ", i + 1) < 0)
						return -1;
				}
			}

			//small optimization
			if (!(lex[0] >= 'a' && lex[0] <= 'z'))
				continue;

			oper = get_statement(lex);
			//if, for, while, switch, do
			//struct, union, class, enum
			//TODO: extern, namespace
			if (oper == IF || oper == FOR || oper == SWITCH ||
				(oper == WHILE && !(st > 0 && stack[st-1].oper == DO && stack[st-1].brace == '-') /*not single do-while*/) ||
				oper == DO || ((oper == STRUCT || oper == UNION || oper == CLASS || oper == ENUM) && parentheses == 0)) {
				//check no code before if, for, etc
				if (!begin_of_code(s, i) && begin_of_statement(prev_lex) && !(oper == IF && !strcmp(prev_lex, "else"))) {
					errors += 10; //1
					return line_break(s, nbuf, i, level, indent, UNKNOWN); //recursion!
				}
				//add new level
				if (st >= NSTACK)
					return -1;
				if (oper == IF || oper == FOR || oper == SWITCH || oper == WHILE)
					state = 'k'; //Keyword was passed
				stack[st].oper = oper;
				stack[st].level = level;
				stack[st].brace = '?';
				st++;
				//do-single-while support
				if (oper == DO && get_next_token(next_lex, sizeof next_lex, s, i + strlen(lex), NULL, NULL) && next_lex[0] != '{') {
					stack[st-1].brace = '-';
					level++;
					if (!end_of_code(s + i + strlen(lex)) && next_lex[0] != ';') {
						errors += 3; //3
						strcpy(prev_lex, lex);
						return line_break(s, nbuf, i + strlen(lex), level, indent, stack[st-1].oper); //recursion!
					}
				}
			} else

			if (oper == ELSE) {
				int next_lex_line = line;
				//don't touch else, if it is followed by "if" or follows "}"
				//before "else"
				if (!get_next_token(next_lex, sizeof next_lex, s, i + strlen(lex), &next_lex_line, NULL))
					continue;
				if (!begin_of_code(s, i) && prev_lex[0] != '}' && !(!strcmp(next_lex, "if") && next_lex_line > line)) { //if next is not "if" on next line
					errors += 4; //2
					return line_break(s, nbuf, i, level, indent, UNKNOWN); //recursion!
				}
				//st is already OK
				if (st <= 0)
					return -1;
				stack[st-1].oper = oper;
				stack[st-1].level = level;
				if (next_lex[0] == '{')
					stack[st-1].brace = '?'; //will be set after
				else {
					stack[st-1].brace = '-';
					level++;
					if (!strcmp(next_lex, "if")) { //if it is "else if", and "if" on a new line, then it can be set instead of "else"
						if (next_lex_line == line)
							level--;
						else
							excuse_indent = -1;
					}
					if (!end_of_code(s + i + strlen(lex)) && strcmp(next_lex, "if") && next_lex[0] != ';') {
						errors += 4; //2
						strcpy(prev_lex, lex);
						return line_break(s, nbuf, i + strlen(lex), level, indent, ELSE); //recursion!
					}
				}
			} else

			if (/*st > 0 && stack[st-1].oper == SWITCH &&*/ !strcmp(lex, "case"))
				state_sw = 'c';
		}
	}
	return 0;
}

//code snippet
#define SNIP_MAX 4
char Snippet[SNIP_MAX][MAX_LINE_LEN];
int snip_len = 0, snip_line = 0;
int snip_dirty[SNIP_MAX] = {0};

int parse_source(char *Data[], int num_lines, FILE *fOutput) {
	char obuf[MAX_LINE_LEN];
	int i, dirty = 0, dirty1, err = 0;
	for (line = 0; line < num_lines; line++) {
		dirty1 = 0;
		strcpy(obuf, Data[line]);
		if (!err) {
			if ((err = parse_line(obuf, sizeof obuf)) != 0) {
				printf("%d: Internal Formatter's ERROR: Syntax error, not enough memory or so on\n", line + 1);
				errors = 0;
				if (!dirty)
					break;
			}
			if (strcmp(Data[line], obuf) != 0) {
				dirty = 1;
				dirty1 = 1;
			}
		}
		if (fOutput) {
			fputs(obuf, fOutput);
			fputs("\n", fOutput);
		}
		//code snippet
		if (dirty && snip_len < SNIP_MAX && errors > 0) {
			if (snip_line == 0)
				snip_line = line + 1;
			strcpy(Snippet[snip_len], obuf);
			// "..." instead of last line
			if (snip_len == SNIP_MAX - 1) {
				char *s;
				for (s = Snippet[snip_len]; *s == ' ' || *s == '\t'; s++);
				*s = '\0';
				strcpy(s, "...");
			}
			snip_dirty[snip_len] = dirty1;
			snip_len++;
		}
	}
	if (dirty) {
		//exclude unchanged bottom lines
		while (snip_len > 0 && !snip_dirty[snip_len-1])
			snip_len--;
		//show example
		if (snip_len > 0) {
			printf("\n\nA sample of exemplary code snippet (starting from line %d):\n", snip_line);
			for (i = 0; i < snip_len; i++)
				puts(Snippet[i]);
		}
		puts("\n");
	}
	return dirty;
}

//read input file data - need to be global for get_next_token function
char **Data = NULL;
int num_lines = 0;

//skip all comments and whitespaces
char *get_next_token(char *buf, int nbuf, const char *s, int i, int *pline, const char **ps) {
	int ln;
	int isComment1 = 0, isComment2 = 0, isMacro = 0;
	if (!buf || !s)
		return NULL;
	//MAIN PARSE
	ln = line;
	if (pline)
		ln = *pline;
	for ( ; ln < num_lines; i++) {
		if (!s[i]) { //goto next line
			if (!(i > 0 && s[i-1] == '\\')) {
				isComment1 = 0;
				isMacro = 0;
			}
			if (++ln >= num_lines)
				break;
			s = Data[ln];
			i = -1;
			continue;
		}
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\r')
			continue;
		if ((s[i] == '/' && s[i+1] == '/' && !isComment2 && !isMacro) || isComment1) { // "//"
			isComment1 = 0;
			if (s[strlen(s)-1] == '\\')
				isComment1 = 1;
			for ( ; s[i]; i++); //skip the rest of string
			i--;
			continue;
		}
		if ((s[i] == '/' && s[i+1] == '*' && !isMacro) || isComment2) { // "/*"
			if (s[i] == '/' && s[i+1] == '*')
				i += 2;
			isComment2 = 0;
			for ( ; s[i]; i++)
				if (s[i] == '*' && s[i+1] == '/') { // "*/"
					i++;
					break;
				}
			if (!s[i]) {
				isComment2 = 1;
				i--;
			}
			continue;
		}
		if (s[i] == '#' || isMacro) {
			isMacro = 0;
			if (s[strlen(s)-1] == '\\')
				isMacro = 1;
			for ( ; s[i]; i++); //skip the rest of string
			i--;
			continue;
		}
		if (pline)
			*pline = ln;
		if (ps)
			*ps = s + i;
		return get_lexeme(buf, nbuf, s + i);
	}
	return NULL;
}

/*void split_tokens(char *Data[], int num_lines) {
	FILE *fTokens;
	if ((fTokens = fopen("tokens1.dbg", "wt")) != NULL) {
		char token[MAX_LEX_LEN];
		const char *s;
		int old_line;
		fprintf(fTokens, "%s\n", Data[0]);
		for (line = 0, s = Data[line];
				get_next_token(token, sizeof token, s, 0, &line, &s);
				old_line = line, s += strlen(token)) {
			if (line != old_line)
				fprintf(fTokens, "%s\n", Data[line]);
			fprintf(fTokens, "%s\n", token);
		}
		fclose(fTokens);
	}
}*/

int main(int argc, char *argv[]) {
	FILE *fInput, *fOutput = NULL;
	char *szInput = NULL, *szOutput = NULL;
	int i;
	//arguments
	if (argc < 2) {
		if (strrchr(argv[0], '/'))
			argv[0] = strrchr(argv[0], '/') + 1;
		printf("Coding Style Checker / Formatter, version 1.11\n");
		printf("USAGE:\n%s [--func | --null] source.file [destination.file]\n", argv[0]);
		printf("    --func\teach function can have its own indent and brace rules\n");
		printf("    --null\tdo not anything, just silently exit and return 0\n");
		printf("Written by Andrey Tretyakov (MIPT), 2014 - 2015, 2019\nCopyright © All Rights Reserved\n");
		return 0;
	}
	for (i = 1; i < argc - 1; i++) {
		if (strcmp(argv[i], "--null") == 0)
			return 0;
		if (strcmp(argv[i], "--func") == 0)
			bFunc = 1; else
		if (fexists(argv[i]))
			szInput = argv[i];
		else
			fprintf(stderr, "Cannot parse option %s\n", argv[i]);
	}
	//set input and output filename
	if (!szInput)
		szInput = argv[i];
	else
		szOutput = argv[i];
	//read input file
	if ((fInput = fopen(szInput, "rt")) != NULL) {
		Data = read_file(fInput, &num_lines);
		fclose(fInput);
	} else
		fprintf(stderr, "fopen(\"%s\"", szInput), perror(", \"rt\")");
	//process and write output file (if any)
	if (Data) {
		if (szOutput)
			if ((fOutput = fopen(szOutput, "wt")) == NULL)
				fprintf(stderr, "fopen(\"%s\"", szOutput), perror(", \"wt\")");
/*		split_tokens(Data, num_lines);
		if (!(fTokens2 = fopen("tokens2.dbg", "wt")))
			return 0;*/
		parse_source(Data, num_lines, fOutput);
//		fclose(fTokens2);
		if (fOutput)
			fclose(fOutput);
		free_data(Data, num_lines);
#ifdef CONTEST
		if (szOutput) {
			void print_file(const char *file);
			print_file(szOutput);
		}
#endif
	}
#ifndef CONTEST
	if (errors > 50)
		printf("Your code is TOO bad!\n\nCoding Style Checker v1.11 ©\nAuthor: Andrey Tretyakov (MIPT), 2014 - 2015, 2019\n");
#ifndef DBG
	if (errors > 0)
		return 1;
#endif
#endif
	return 0;
}
