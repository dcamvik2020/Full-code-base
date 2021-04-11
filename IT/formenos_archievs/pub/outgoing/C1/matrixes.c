#include <stdio.h>

#define MAX_LEN 100

int main(void)
{
	unsigned m, n, o, p, i, j, h;
	int A[MAX_LEN][MAX_LEN], B[MAX_LEN][MAX_LEN], C;
	scanf("%u %u %u %u", &m, &n, &o, &p);
	if (n != o)
	{
		printf("-1\n");
		return 0;
	}
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	for (i = 0; i < n; i++)
		for (j = 0; j < p; j++)
			scanf("%d", &B[i][j]);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < p; j++)
		{
			C = 0; //C[i][j]
			for (h = 0; h < n; h++)
				C += A[i][h] * B[h][j]; //C[i][j]
			printf("%d ", C);
		}
		printf("\n");
	}
	return 0;
}
