#include <stdio.h>
#include <math.h>

#define BIT(x) (1 << (x) % 8)

unsigned char A[25000001];

int main(void)
{
	unsigned i, j, n, r, k = 0;
	scanf("%u", &n);
	r = (unsigned) sqrt(n);
	for (i = 2; i <= r; i++)
		if (!(A[i/8] & BIT(i)))
			for (j = i * i; j <= n; j += i)
				A[j/8] |= BIT(j);
	for (i = 2; i <= n; i++)
		if (!(A[i/8] & BIT(i)))
			k++;
	printf("%u\n", k);
	return 0;
}
