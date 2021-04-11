#include <stdio.h>

int main(void) {
	unsigned char a1, b1, c1, d1, a2, b2, c2, d2;
	scanf("%hhu.%hhu.%hhu.%hhu %hhu.%hhu.%hhu.%hhu", &a1, &b1, &c1, &d1, &a2, &b2, &c2, &d2);
	printf("%hhu.%hhu.%hhu.%hhu\n", a1 | ~a2, b1 | ~b2, c1 | ~c2, d1 | ~d2);
	return 0;
}
