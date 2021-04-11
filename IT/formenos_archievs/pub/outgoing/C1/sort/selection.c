#include <stdio.h>

#define N_MAX 100

void sort(int A[], unsigned n) {
	int m;
	unsigned i, j, k;
	for (i = 0; i < n - 1; i++) {
		k = i;
		m = A[k];
		//seek for current minimum (maximum)
		for (j = i + 1; j < n; j++)
			if (A[j] < m) {
				k = j;
				m = A[k];
			}
		//and replace current item and found minimum
		A[k] = A[i];
		A[i] = m;
	}
}

int main(void) {
	int A[N_MAX];
	unsigned n, i;
	printf("Enter the dimension: ");
	scanf("%u", &n);
	if (n > N_MAX) {
		printf("Error! Too many!\nMax = %u\n", N_MAX);
		return -1;
	}
	printf("Enter %u elements: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A, n);
	printf("Your sorted array:\n");
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}
