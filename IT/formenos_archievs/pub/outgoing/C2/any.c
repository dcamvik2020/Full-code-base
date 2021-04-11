#include <stdio.h>

int main(void)
{
	char s[33], c;
	unsigned i, n, a = 0, k;
	scanf("%u %s %u", &n, s, &k);
/*	if (n == k)
	{
		printf("%s\n", s);
		return 0;
	}*/
	for (i = 0; s[i]; i++)
	{
		c = s[i];
		if (c >= '0' && c <= '9')
			c -= '0'; else
		if (c >= 'A' && c <= 'Z')
			c -= 'A' - 10; else
		if (c >= 'a' && c <= 'z')
			c -= 'a' - 10;
		a = a * n + c;
	}
	i = 0;
	do {
		c = a % k;
		a /= k;
		if (c < 10)
			c += '0';
		else
			c += 'A' - 10;
		s[i++] = c;
	} while (a);
	s[i] = '\0';
	n = i;
	for (i = 0; i < n / 2; i++)
	{
		c = s[i];
		s[i] = s[n-i-1];
		s[n-i-1] = c;
	}
	puts(s);
	return 0;
}
