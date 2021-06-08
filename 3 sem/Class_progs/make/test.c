#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int i, j, n, m;
	int **A;
	printf("Enter n, m: ");
	scanf("%d %d", &n, &m);
//	sqrt(n);
	A = (int **) malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		A[i] = (int *) malloc(m * sizeof(int));

	printf("Enter matrix %d x %d:\n", n, m);
	for (i = 0; i < n; i++) {
		printf("Line %d:\n", i);
		for (j = 0; j < m; j++) {
			scanf("%d", &A[i][j]);
			fprintf(stderr, "%d ", A[i][j]);
		}
		fprintf(stderr, "\n");
	}
	
	printf("\nMatrix %d x %d:\n", n, m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}

	for (i = 0; i < n; i++)
		free(A[i]);
	free(A);
	return 0;
}
