#include <stdio.h>

float f1, f2;

int main(void) {
	scanf("%f %f", &f1, &f2);
	//version 1
	__asm (
		"fld f1\n"
		"fld f2\n"
		"fsubrp\n"		//fsubrp %st(0), %st(1)	//st(1) = st(1) - st(0); pop
		"fstp f1\n"
	);
	//version 2
/*	__asm (
		"fld f1\n"
		"fsub f2\n"		//fsubr f2, st(0)	//(illegal)
		"fstp f1\n"
	);*/
	printf("%g\n", f1);
	return 0;
}
