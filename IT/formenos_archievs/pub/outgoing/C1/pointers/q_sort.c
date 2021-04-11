#include <stdio.h>
#include <stdlib.h>

int cmp_func1(const void *p1, const void *p2) {
	const int *pa, *pb;
	int a, b;
	pa = (const int *) p1;
	pb = (const int *) p2;
	a = *pa;
	b = *pb;
	if (a > b)
		return 1;
	if (a < b)
		return -1;
	return 0;
}

int cmp_func2(const void *p1, const void *p2) {
	int a, b;
	const int *pa = (const int *) p1;
	const int *pb = (const int *) p2;
	a = *pa;
	b = *pb;
	return a - b;
}

int cmp_func3(const void *p1, const void *p2) {
	const int *pa, *pb;
	pa = (const int *) p1;
	pb = (const int *) p2;
	return *pa - *pb;
}

int cmp_func(const void *p1, const void *p2) {
	return *(const int *)p1 - *(const int *)p2;
}

int main(void) {
	int i, n, A[] = {1, 5, 2, 4, 3};
	n = sizeof A / sizeof A[0];
	qsort(A, n, sizeof(int), cmp_func);
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
	return 0;
}
