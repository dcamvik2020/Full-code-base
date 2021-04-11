#include <stdio.h>

int main(void) {
	int i1 = 10, i2 = 20, i3 = 30;
	int *p = &i2;
	printf("%d\n", *&i2); //20
	printf("%d\n", *p); //20
	printf("%d\n", *p++); //20	//equivalent *(p++)
	printf("%d\n", *p); //10
	printf("%d\n", ++*p); //11
	printf("%d\n", *--p); //20
	printf("%d\n", ++*--p); //31
	return 0;
}
