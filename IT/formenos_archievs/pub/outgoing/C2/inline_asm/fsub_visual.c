#include <stdio.h>

int main(void) {
	float f1, f2;
	scanf("%f %f", &f1, &f2);
	//version 1
	_asm {
		fld f1
		fld f2
		fsub	//fsubp st(1), st(0)	//st(1) = st(1) - st(0); pop
		fstp f1
	}
	//version 2
/*	__asm {
		fld f1
		fsub f2	//fsub st(0), f2	//(illegal)
		fstp f1
	}*/
	printf("%g\n", f1);
	return 0;
}
