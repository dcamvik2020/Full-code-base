#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "mega.c"

#define USERTEST_NUM 3

char *my_fgets(char *s, int N, FILE *input) {
	int n;
	if (!fgets(s, N, input))
		return NULL;
	//remove "\r\n" from string
	for (n = 0; s[n]; n++); //n = strlen(s1);
	while (n > 0 && (s[n-1] == '\r' || s[n-1] == '\n'))
		s[--n] = '\0';
	return s;
}

int get_max_test_num(const char *dirname) {
	DIR *pDir;
	struct dirent *pEntry;
	char filename[1024], *p;
	int num, maxnum = 0;
	//enumerate all files in directory
	if ((pDir = opendir(dirname)) != NULL) {
		while ((pEntry = readdir(pDir)) != NULL) {
			if ((pEntry->d_type & DT_DIR) == 0) {
				//omit extension
				strcpy(filename, pEntry->d_name);
				if ((p = strrchr(filename, '.')) != NULL && strcmp(p, ".dat") == 0)
					*p = '\0';
				//convert string to integer
				num = atoi(filename);
				if (num > maxnum)
					maxnum = num;
			}
		}
		closedir(pDir);
	} else
		perror("opendir");
	return maxnum;
}

int has_test(FILE *fTests, const char *test, int num) {
	char s[102];
	int x;
	//check magic header to ensure that it is megatest file
	if (!my_fgets(s, sizeof s, fTests)) {
		printf("Cannot read input of megatest file\n");
		return 4;
	}
	if (strncmp(s, "Other tests # ", 14) != 0) {
		printf("Found file is not megatest file\n");
		return 5;
	}
	//extract the number of ordinary tests from megatest file
	if (sscanf(s + 14, "%d", &x) != 1) {
		printf("Cannot extract the number of tests\n");
		return 4;
	}
	if (x + USERTEST_NUM != num) {
		printf("Wrong the number of tests in megatest file\n");
		return 5;
	}
	//read all file line by line and compare with "test"
	while (my_fgets(s, sizeof s, fTests))
		if (strcmp(s, test) == 0)
			return 1;
	return 0;
}

int add_test(const char *test) {
	const char *dirname = "";
	int num, res = 0;
	char filename[1024];
	FILE *fTests;
	num = get_max_test_num(dirname);
	sprintf(filename, "%s/%03d.dat", dirname, num);
	if ((fTests = fopen(filename, "rt")) != NULL) {
		res = has_test(fTests, test, num);
		fclose(fTests);
	} else
		perror("fopen(fTests, rt)");
	if (res) //test is not to be added
		return 0;
	res = 0;
	//finally, open file for writing and append test
	if ((fTests = fopen(filename, "at")) != NULL) {
		fprintf(fTests, "%s\n", test);
		res = 1;
		fclose(fTests);
	} else
		perror("fopen(fTests, at)");
	return res;
}

int check_test(char *s1, FILE *output, int ch, int r1, int r2) {
	char s2[202], st[202];
	strcpy(st, s1);

	//result of 'check'
	if (!my_fgets(s2, sizeof s2, output)) {
		printf("Cannot read output (result of 'check')\n");
		return 4;
	}
	if (strcmp(s2, "-- check --") != 0)
		return 4;
	//result of 'check'
	if (!my_fgets(s2, sizeof s2, output)) {
		printf("Cannot read output (result of 'check')\n");
		return 4;
	}
	//compare 'checks'
	if (strcmp(s2, "true") == 0) {
		if (!checks[ch-1](s1)) {
			printf("'check' failed: should be 'false' instead of 'true'\n");
			return 5;
		}
	} else
	if (strcmp(s2, "false") == 0) {
		if (checks[ch-1](s1)) {
			printf("'check' failed: should be 'true' instead of 'false'\n");
			return 5;
		}
	} else {
		printf("Unknown 'check' result: %s\n", s2);
		return 4;
	}

	//result of 'rule1'
	if (!my_fgets(s2, sizeof s2, output)) {
		printf("Cannot read output (result of 'rule1')\n");
		return 4;
	}
	if (strcmp(s2, "-- rule1 --") != 0)
		return 4;
	//result of 'rule1'
	if (!my_fgets(s2, sizeof s2, output)) {
		printf("Cannot read output (result of 'rule1')\n");
		return 4;
	}
	//compare 'rules1'
	rules1[r1-1](s1);
	if (strcmp(s1, s2) != 0) {
		printf("Correct result of 'rule1' should be: '%s'\n", s1);
		return 5;
	}

	//result of 'rule2'
	if (!my_fgets(s2, sizeof s2, output)) {
		printf("Cannot read output (result of 'rule2')\n");
		return 4;
	}
	if (strcmp(s2, "-- rule2 --") != 0)
		return 4;
	//result of 'rule2'
	if (!my_fgets(s2, sizeof s2, output)) {
		printf("Cannot read output (result of 'rule2')\n");
		return 4;
	}
	//compare 'rules2'
	rules2[r2-1](st);
	if (strcmp(st, s2) != 0) {
		printf("Correct result of 'rule2' should be: '%s'\n", st);
		return 5;
	}

	return 0;
}

int check(FILE *input, FILE *output, FILE *correct) {
//	return 0; //OK
//	return 4; //Wrong format
//	return 5; //Wrong answer
//	return -1; //EJudge internal system error
	char s1[202], s2[202], *p1, *p2;
	int n = 0;
	//check for user tests
	if (!my_fgets(s1, sizeof s1, input)) {
		printf("Cannot read input\n");
		return 4;
	}
	if (strncmp(s1, "User test # ", 12) == 0) {
		int x, ch, r1, r2;
		//extract numbers from input
		if (sscanf(s1 + 12, "%d", &x) != 1) {
			printf("Cannot extract test number\n");
			return 4;
		}
		if (fscanf(correct, "%d %d %d", &ch, &r1, &r2) != 3) {
			printf("Cannot extract variants numbers\n");
			return 4;
		}
		//user source string
		if (!my_fgets(s1, sizeof s1, output)) {
			printf("Cannot read output (user source string)\n");
			return 4;
		}
		if (strcmp(s1, "-- User test --") != 0)
			return 4;
		//user source string
		if (!my_fgets(s1, sizeof s1, output)) {
			printf("Cannot read output (user source string)\n");
			return 4;
		}
		add_test(s1);
		return check_test(s1, output, ch, r1, r2);
	} else
	if (strncmp(s1, "Other tests # ", 14) == 0) {
		int x, ch, r1, r2, n, res;
		//extract numbers from input
		if (sscanf(s1 + 14, "%d", &x) != 1) {
			printf("Cannot extract test number\n");
			return 4;
		}
		if (fscanf(correct, "%d %d %d", &ch, &r1, &r2) != 3) {
			printf("Cannot extract variants numbers\n");
			return 4;
		}
		//skip ordinary tests (already checked)
		for (n = 1; n < x && my_fgets(s1, sizeof s1, input); n++);
		for ( ; my_fgets(s1, sizeof s1, input); n++) {
			//source string
			if (!my_fgets(s2, sizeof s2, output)) {
				printf("Cannot read output (source string)\n");
				return 4;
			}
			if (strncmp(s2, "-- Users' test # ", 17) != 0)
				return 4;
			//source string
			if (!my_fgets(s2, sizeof s2, output)) {
				printf("Cannot read output (source string)\n");
				return 4;
			}
			//compare source strings
			if (strcmp(s1, s2) != 0) {
				printf("Correct source string should be: '%s'\n", s1);
				return 5;
			}
			if ((res = check_test(s1, output, ch, r1, r2)) != 0) {
				printf("Test # %d\n", n);
				return res;
			}
			//empty string (delimiter)
			if (!my_fgets(s2, sizeof s2, output)) {
				printf("Cannot read output (empty string)\n");
				return 4;
			}
			if (strcmp(s2, "") != 0)
				return 4;
		}
		return 0;
	}
	//ordinary tests
	while (1) {
		p1 = my_fgets(s1, sizeof s1, output);
		p2 = my_fgets(s2, sizeof s2, correct);
		n++;
		if (!p1 || !p2)
			break;
		if (strcmp(s1, s2) != 0) {
			printf("Lines %d differ: '%s' instead of '%s'\n", n, s1, s2);
			return 5;
		}
	}
	if (p1) {
		printf("Too many lines in output\n");
		return 5;
	}
	if (p2) {
		printf("Too few lines in output\n");
		return 5;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int res = 0;
	FILE *input, *output, *correct;
	if (argc < 4)
		return -1;
	if ((input = fopen(argv[1], "rt")) != NULL) {
		if ((output = fopen(argv[2], "rt")) != NULL) {
			if ((correct = fopen(argv[3], "rt")) != NULL) {
				res = check(input, output, correct);
				fclose(correct);
			} else
				perror("fopen(correct)");
			fclose(output);
		} else
			perror("fopen(output)");
		fclose(input);
	} else
		perror("fopen(input)");
	return res;
}
