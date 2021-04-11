#include <stdio.h>
#include <string.h>

#define N 6
#define START_CHAR ' '
#define STOP_CHAR '~'

int check(char *pass);

int bruteforce(char *s, unsigned n) {
	int i = 0;
	char c;
	for (c = START_CHAR; c <= STOP_CHAR; c++) {
		for (i = 0; i < N; i++)
			s[i] = c;
		s[i] = '\0';
		if (check(s))
			return 1;
	}
	return 0;
}

int main(void) {
	char buf[N+1];
	if (bruteforce(buf, sizeof buf))
		puts(buf);
	return 0;
}
