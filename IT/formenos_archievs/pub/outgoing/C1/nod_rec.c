#include <stdio.h>

unsigned long gcd(unsigned long a, unsigned long b) {
	if (!b)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	unsigned long a, b;
	scanf("%lu %lu", &a, &b);
	printf("%lu\n", gcd(a, b));
	return 0;
}
