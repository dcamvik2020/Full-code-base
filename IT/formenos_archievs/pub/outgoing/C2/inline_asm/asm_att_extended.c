#include <stdio.h>

int main(void) {
	int a1, b1;
	scanf("%d %d", &a1, &b1);
	__asm (
		"addl %%ebx, %%eax\n"
		"subl $3, %%eax\n"
		: "=a"(a1)		//output "=eax" -> a1
		: "a"(a1), "b"(b1)	//input a1 -> "eax", b1 -> "ebx"
//		: "a"			//modify "eax"
		);
	printf("%d\n", a1);
	return 0;
}
