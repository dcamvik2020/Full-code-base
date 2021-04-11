#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, j, n, m, **A;
	scanf("%d %d", &n, &m);
	//alloc
	A = (int **) malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		A[i] = (int *) malloc(m * sizeof(int));
	//use
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &A[i][j]);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%3d ", A[i][j]);
		printf("\n");
	}
	//free
	for (i = 0; i < n; i++)
		free(A[i]);
	free(A);
	return 0;
}
