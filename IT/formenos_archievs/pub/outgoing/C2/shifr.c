#include <stdio.h>

int main(void) {
	int i, x;
	char s[1024];
	do {
		printf("Enter value between 0 and 32: ");
		scanf("%d", &x);
	} while (x >= 32 || x < 0);
	printf("Accepted key: %d\nEnter string:\n", x);
	while (fgets(s, sizeof s, stdin) && s[0] == '\n');

	for (i = 0; s[i]; i++)
		s[i] ^= x;
	puts("Encoded string:");
	puts(s);

	for (i = 0; s[i]; i++)
		s[i] ^= x;
	puts("Decoded string:");
	puts(s);
	return 0;
}
