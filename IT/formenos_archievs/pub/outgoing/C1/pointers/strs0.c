#include <stdio.h>

int strcompare(const char *s1, const char *s2) {
	int i;
	for (i = 0; s1[i] /*&& s2[i]*/ && s1[i] == s2[i]; i++);
//	return s1[i] - s2[i];
	return s1[i] > s2[i] ? 1 :
			s1[i] < s2[i] ? -1 : 0;
}

int main(void) {
	int i, n;
	char s[256], t[256], c;
	gets(s);

	//strlen()
	for (n = 0; s[n]; n++);

	//different version of strlen()
	n = 0;
	while (s[n++]); n--;

	//reverse
	for (i = 0; i < n / 2; i++) {
		c = s[i];
		s[i] = s[n-i-1];
		s[n-i-1] = c;
	}

	//strcpy()
	for (i = 0; s[i]; i++)
		t[i] = s[i];
	t[i] = '\0';

	//another strcpy()
	for (i = 0; t[i] = s[i]; i++);

	printf("%d\n%s\n", n, t);
	t[1] = 'e';		//strcmp()
	printf("s %c t\n", strcompare(s, t) + '=');
	return 0;
}
