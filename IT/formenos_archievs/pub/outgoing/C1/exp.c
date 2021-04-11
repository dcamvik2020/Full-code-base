#include <stdio.h>

#define N 10000

int main(void)
{
	double S, x, f;
	int i;
	scanf("%lf", &x);
	S = f = 1;
	for (i = 1; i <= N; i++)
	{
		f *= x / i;
		S += f;
	}
	printf("%lg\n", S);
	return 0;
}
