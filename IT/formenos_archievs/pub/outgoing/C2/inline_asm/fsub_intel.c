#include <stdio.h>

float f1, f2;

int main(void) {
	scanf("%f %f", &f1, &f2);
	//version 1
	__asm (".intel_syntax noprefix\n"
		"fld dword ptr [f1]\n"
		"fld dword ptr [f2]\n"
		"fsubp\n"			//fsubp st(1), st(0)	//st(1) = st(1) - st(0); pop
		"fstp dword ptr [f1]\n"
		".att_syntax\n");
	//version 2
/*	__asm (".intel_syntax noprefix\n"
		"fld dword ptr [f1]\n"
		"fsub dword ptr [f2]\n"		//fsub st(0), f2	//(illegal)
		"fstp dword ptr [f1]\n"
		".att_syntax\n");*/
	printf("%g\n", f1);
	return 0;
}
