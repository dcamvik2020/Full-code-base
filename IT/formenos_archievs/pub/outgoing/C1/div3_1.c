#include <stdio.h>

int main(void)
{
	char s[1001];
	int i, k = 0;
	gets(s);
	for (i = 0; s[i]; i++)
		k += s[i] - '0';
	if (k % 3)
		puts("NO");
	else
		puts("YES");
	return 0;
}
