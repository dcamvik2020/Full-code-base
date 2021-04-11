#include <stdio.h>

int N, K;
char A[21];

//n - current position (the number of fixed first characters in the array)
//k - the number of expended (израсходованные) 1's
void recur(int n, int k)
{
	if (n >= N) //if all array is filled
	{
		puts(A);
		return;
	}
	if (n - k < N - K) //if there are unexpended 0's
	{
		A[n] = '0';
		recur(n + 1, k);
	}
	if (k < K) //if there are unexpended 1's
	{
		A[n] = '1';
		recur(n + 1, k + 1);
	}
}

int main(void)
{
	scanf("%d %d", &N, &K);
	A[N] = '\0';
	recur(0, 0);
	return 0;
}
