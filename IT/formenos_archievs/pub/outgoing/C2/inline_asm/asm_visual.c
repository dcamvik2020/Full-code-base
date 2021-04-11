#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	__asm {
		mov eax, a
		add eax, b
		sub eax, 3
		mov a, eax
	}
	printf("%d\n", a);
	return 0;
}
