#include <stdio.h>

union IP {
	unsigned int i;
	unsigned char b[4];
};

int main(void) {
	union IP ip, mask;
	scanf("%hhu.%hhu.%hhu.%hhu", &ip.b[0], &ip.b[1], &ip.b[2], &ip.b[3]);
	scanf("%hhu.%hhu.%hhu.%hhu", &mask.b[0], &mask.b[1], &mask.b[2], &mask.b[3]);
	ip.i |= ~mask.i;
	printf("%hhu.%hhu.%hhu.%hhu\n", ip.b[0], ip.b[1], ip.b[2], ip.b[3]);
	return 0;
}
