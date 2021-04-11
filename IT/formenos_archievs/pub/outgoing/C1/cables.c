#include <stdio.h>

unsigned long n, k, A[10000];

int check(unsigned long l)
{
	unsigned long i, m = 0;
	for (i = 0; i < n; i++)
		m += A[i] / l;
	if (m >= k)
		return 1;
	return 0;

}

int main(void)
{
	unsigned long i, l = 0, l1, l2;
	scanf("%lu %lu", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%lu", &A[i]);
		l += A[i];
	}
	l1 = 1, l2 = l / k;
	if (l2 < l1 || !check(l1))
	{
		printf("0\n");
		return 0;
	}
	if (check(l2))
	{
		printf("%lu\n", l2);
		return 0;
	}
	while (l1 < l2 - 1)
	{
		l = l1 + (l2 - l1) / 2;
		if (check(l))
			l1 = l;
		else
			l2 = l;
	}
	printf("%lu\n", l1);
	return 0;
}
