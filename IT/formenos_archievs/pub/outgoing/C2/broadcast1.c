#include <stdio.h>

int main(void) {
	unsigned a1, b1, c1, d1, a2, b2, c2, d2;
	scanf("%u.%u.%u.%u %u.%u.%u.%u", &a1, &b1, &c1, &d1, &a2, &b2, &c2, &d2);
	a2 = ~a2 & 0xFF; b2 = ~b2 & 0xFF; c2 = ~c2 & 0xFF; d2 = ~d2 & 0xFF;
	printf("%u.%u.%u.%u\n", a1 | a2, b1 | b2, c1 | c2, d1 | d2);
	return 0;
}
