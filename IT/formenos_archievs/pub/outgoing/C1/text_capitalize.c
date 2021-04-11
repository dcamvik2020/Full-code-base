#include <stdio.h>

int main(void)
{
	char s[1001];
	int i, lastchar = 0;
	gets(s);
	for (i = 0; s[i]; i++)
	{
		if (!lastchar && s[i] >= 'a' && s[i] <= 'z')
			s[i] += 'A' - 'a';
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			lastchar = 1;
		else
			lastchar = 0;
	}
	puts(s);
	return 0;
}
