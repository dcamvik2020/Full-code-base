#include <stdio.h>

void swap(int *x, int *y) {
	int z = *x;
	*x = *y;
	*y = z;
}

int main(void) {
	int a = 10, b = 20;
	swap(&a, &b);
	printf ("%d %d\n", a, b);
	return 0;
}
