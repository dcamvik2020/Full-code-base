
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(const char *s);
void rule1(char *s);
void rule2(char *s);
const char *test(int i);
int _main(int argc, char *argv[], char *envp[]);

#define NT 4

static char *my_fgets(char *s, int N, FILE *input) {
	int n;
	if (!fgets(s, N, input))
		return NULL;
	//remove "\r\n" from string
	for (n = 0; s[n]; n++); //n = strlen(s1);
	while (n > 0 && (s[n-1] == '\r' || s[n-1] == '\n'))
		s[--n] = '\0';
	return s;
}

//make no extra functions

int main(int argc, char *argv[], char *envp[]) {
	FILE *input;
	//first string from input is used to determine the type of test - read it from input file rather than from stdin because user will read it too (twice read)
	if (argc > 1 && (input = fopen(argv[1], "r")) != NULL) {
		char s[102], s1[202];
		int do_main = 1;
		my_fgets(s1, sizeof s1, input);
		strcpy(s, s1);
		//mega-test - other (users') tests
		if (strncmp(s, "Other tests # ", 14) == 0) {
			int x, n;
			//extract numbers from input
			if (sscanf(s + 14, "%d", &x) != 1) {
				fprintf(stderr, "Cannot extract the number of tests\n");
				fclose(input);
				return -1;
			}
			//skip ordinary tests (will be separately checked)
			for (n = 1; n < x && my_fgets(s, sizeof s, input); n++);
			//all users' tests
			for ( ; my_fgets(s, sizeof s, input); n++) {
				//test by functions
				strcpy(s1, s);
				printf("-- Users' test # %d --\n", n);
				puts(s);
				puts("-- check --");
				puts(check(s) ? "true" : "false");
				puts("-- rule1 --");
				rule1(s);
				puts(s);
				puts("-- rule2 --");
				rule2(s1);
				puts(s1);
				puts("");
			}
			fclose(input);
			return 0;
		}
		fclose(input);
		//check for user tests
		if (strncmp(s, "User test # ", 12) == 0) {
			int x, i, j, lc = 0, uc = 0, dg = 0, chr = 0, tr = 0, fl = 0;
			const char *p, *q;
			char *T[NT] = {0};
			do_main = 0;
			//extract numbers from input
			if (sscanf(s + 12, "%d", &x) != 1) {
				fprintf(stderr, "Cannot extract test number\n");
				return -1;
			}
			if (x >= NT) {
				fprintf(stderr, "Too large test number\n");
				return -1;
			}
			//get user source string - call test
			p = T[x] = T[x] ? T[x] : strdup(test(x));
			//check length
			if (strlen(p) < 3) {
				fprintf(stderr, "Too short test string: \"%s\"\n", p);
				free(T[x]);
				return -2;
			}
			if (strlen(p) > 100) {
				fprintf(stderr, "Too long test string: \"%s\"\n", p);
				free(T[x]);
				return -2;
			}
			//check content
			for (i = 1; p[i]; i++)
				if (p[i] != p[0])
					break;
			if (!p[i]) {
				fprintf(stderr, "Too simple test string: \"%s\". Give more different characters!\n", p);
				free(T[x]);
				return -3;
			}
			for (i = 0; p[i]; i++)
				if (p[i] < ' ' || p[i] > '~') {
					fprintf(stderr, "Non-ASCII symbol #%hhu at %d position: '...%.10s...'\n", p[i], i + 1, p + i);
					free(T[x]);
					return -3;
				}
			//check that this test had not appeared before
			for (i = 1; i < x; i++) {
				q = T[i] = T[i] ? T[i] : strdup(test(i));
				if (strcmp(p, q) == 0) {
					fprintf(stderr, "This test is the same as test # %d: \"%s\"\n", i, p);
					for (j = 0; j < NT; j++)
						if (T[j])
							free(T[j]);
					return -4;
				}
			}
			//check that all tests contain digits, upper- and lower-case letters and other symbols
			for (i = 1; i < NT; i++) {
				q = T[i] = T[i] ? T[i] : strdup(test(i));
				for (j = 0; q[j]; j++)
					if (q[j] >= '0' && q[j] <= '9')
						dg++; else
					if (q[j] >= 'A' && q[j] <= 'Z')
						uc++; else
					if (q[j] >= 'a' && q[j] <= 'z')
						lc++;
					else
						chr++;
			}
			if (!dg || !uc || !lc || !chr) {
				if (!dg)
					fprintf(stderr, "At least one of your tests 1 - %d must contain at least one digit\n", NT - 1);
				if (!uc)
					fprintf(stderr, "At least one of your tests 1 - %d must contain at least one upper-case letter\n", NT - 1);
				if (!lc)
					fprintf(stderr, "At least one of your tests 1 - %d must contain at least one lower-case letter\n", NT - 1);
				if (!chr)
					fprintf(stderr, "At least one of your tests 1 - %d must contain at least one character (non-digit and non-letter)\n", NT - 1);
				for (i = 0; i < NT; i++)
					if (T[i])
						free(T[i]);
				return -5;
			}
			//check that there is "true" and "false" for check(test(i))
			for (i = 1; i < NT; i++)
				if (check(T[i]))
					tr++;
				else
					fl++;
			if (!tr || !fl) {
				if (!tr)
					fprintf(stderr, "At least one of your tests 1 - %d must pass the condition (check must return 'true')\n", NT - 1);
				if (!fl)
					fprintf(stderr, "At least one of your tests 1 - %d must break the condition (check must return 'false')\n", NT - 1);
				for (i = 0; i < NT; i++)
					if (T[i])
						free(T[i]);
				return -6;
			}
			//user source string
			strcpy(s, p);
			puts("-- User test --");
			puts(s);
			for (i = 0; i < NT; i++)
				if (T[i])
					free(T[i]);
		}
		//ordinary tests
		//test by functions
		strcpy(s1, s);
		puts("-- check --");
		puts(check(s) ? "true" : "false");
		puts("-- rule1 --");
		rule1(s);
		puts(s);
		puts("-- rule2 --");
		rule2(s1);
		puts(s1);
		if (!do_main)
			return 0;
		puts("-- User output --");
	} else
		perror("fopen(input)");
	//call user's main
	return _main(argc, argv, envp);
}
