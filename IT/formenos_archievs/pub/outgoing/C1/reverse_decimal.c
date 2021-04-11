#include <stdio.h>

int main(void)
{
	unsigned N;
	scanf("%u", &N);
	while (N && N % 10 == 0)
		N /= 10;
	while (N)
	{
		printf("%u", N % 10);
		N /= 10;
	}
	printf("\n");
	return 0;
}
