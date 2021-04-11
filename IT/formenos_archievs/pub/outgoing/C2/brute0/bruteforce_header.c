
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START_CHAR '0'
#define STOP_CHAR '9'

char riddle[4096];
unsigned long attempts;

int check(const char *pass) {
	attempts++;
	return !strcmp(pass, riddle);
}

int bruteforce(char *s, unsigned n);

int main(void) {
	char *buf;
	unsigned n = 0;
	if (!fgets(riddle, sizeof riddle, stdin))
		return -1;
	if (scanf("%u", &n) == 1) {
		unsigned l = strlen(riddle);
		if (l > 0)
			if (riddle[l-1] == '\n') {
				riddle[l-1] =  '\0';
				n--;
			}
	} else {
		n = strlen(riddle);
		if (n > 0)
			if (riddle[n-1] == '\n') {
				riddle[n-1] =  '\0';
				n--;
			}
	}
	buf = (char *) malloc(n + 1);
	attempts = 0;
	if (bruteforce(buf, n + 1))
		puts(buf);
	else
		printf("%lu\n", attempts);
	free(buf);
	return 0;
}
