#include <stdio.h>

int a, b;

int main(void) {
	scanf("%d %d", &a, &b);
	__asm (".intel_syntax noprefix\n"
		"mov eax, _a\n"
		"add eax, _b\n"
		"sub eax, 3\n"
		"mov _a, eax\n"
		".att_syntax\n");
	printf("%d\n", a);
	return 0;
}
