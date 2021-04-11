#include <stdio.h>

int main(void) {
	int i, n, m, A[16];
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		A[i] = i;
	for (i = 0; i < m; i++)
		printf("%d ", A[i]);
	return 0;
}
