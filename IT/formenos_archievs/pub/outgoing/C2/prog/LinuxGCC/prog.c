#include <stdio.h>
#include "header.h"

#define ABS(x) ((x) > 0 ? (x) : -(x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define N 5

int main(void)
{
	int i, m = 0, A[N];
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		m = MAX(m, ABS(A[i]));
	}
	printf("max = %d\nsum = %d\n", m, sum(A, N));
	sort(A, sizeof A / sizeof A[0]);
	for (i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");
	return 0;
}
