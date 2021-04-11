#include <stdio.h>
#include <stdlib.h>

void strcopy(char *t, const char *s) {
	while (*t++ = *s++);
}

int strcompare1(const char *s1, const char *s2) {
	int i;
	for (i = 0; s1[i] /*&& s2[i]*/ && s1[i] == s2[i]; i++);
//	return s1[i] - s2[i];
	return s1[i] > s2[i] ? 1 :
			s1[i] < s2[i] ? -1 : 0;
}

int strcompare(const char *s1, const char *s2) {
	while (*s1 /*&& *s2*/ && *s1 == *s2)
		s1++, s2++;
//	return (unsigned char) *s1 - (unsigned char) *s2;
	return (unsigned char) *s1 > (unsigned char) *s2 ? 1 :
			(unsigned char) *s1 < (unsigned char) *s2 ? -1 : 0;
}

int main(void) {
	int i, n;
	char s[256], *t, c;
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

	t = (char *) malloc((n + 1) * sizeof(char));

	//strcpy()
	for (i = 0; s[i]; i++)
		t[i] = s[i];
	t[i] = '\0';

	//another strcpy()
	for (i = 0; t[i] = s[i]; i++);

	//one more strcpy()
	strcopy(t, s); // while (*t++ = *s++);

	printf("%d\n%s\n", n, t);
	t[1] = 'e';		//strcmp()
	printf("s %c t\n", strcompare(s, t) + '=');
	free(t);
	return 0;
}
