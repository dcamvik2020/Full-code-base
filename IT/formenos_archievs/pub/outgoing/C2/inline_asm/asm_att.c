#include <stdio.h>

int a, b;

int main(void) {
	scanf("%d %d", &a, &b);
	__asm (
		"movl _a, %eax\n"
		"addl _b, %eax\n"
		"subl $3, %eax\n"
		"movl %eax, _a\n"
	);
	printf("%d\n", a);
	return 0;
}
