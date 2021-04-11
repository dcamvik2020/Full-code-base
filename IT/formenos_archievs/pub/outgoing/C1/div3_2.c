#include <stdio.h>

int main(void)
{
	char c;
	int k = 0;
	while ((c = getchar()) != '\n' && c != ' ' && c != EOF)
		k += c - '0';
	if (k % 3)
		puts("NO");
	else
		puts("YES");
	return 0;
}
