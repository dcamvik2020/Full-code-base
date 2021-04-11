#include <stdio.h>

int main(void)
{
	char s[112];
	freopen("input.txt", "rb", stdin);
	gets(s);
	puts(s);
	fclose(stdin);
	return 0;
}
