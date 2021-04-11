#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	__asm {
		mov eax, a
		add eax, b
		mov a, eax
		call l1
		jmp l2
		l1:
		inc a
		ret
		l2:
	}
	printf("%d\n", a);
	return 0;
}
