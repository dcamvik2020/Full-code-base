#include <stdio.h>

int main(void) {
	int i, j, n, m;
	long A[21][21];
	scanf("%d %d", &n, &m);
	for (i = 0; i <= n; i++)
		A[i][0] = 1;
	for (j = 0; j <= m; j++)
		A[0][j] = 1;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			A[i][j] = A[i-1][j] + A[i][j-1];
	printf("%ld\n", A[n][m]);
	return 0;
}
