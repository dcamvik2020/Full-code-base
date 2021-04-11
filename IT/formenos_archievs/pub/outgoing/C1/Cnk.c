#include <stdio.h>

unsigned long C[1024][1024];

int main(void)
{
	unsigned long i, j, n, k;
	scanf("%lu %lu", &n, &k);
	C[0][0] = 1;
	for (i = 1; i <= n; i++)
	{
		C[i][0] = 1;
		for (j = 1; j <= i; j++)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
	printf("%lu\n", C[n][k]);
	return 0;
}
