#include <stdio.h>
#include <stdlib.h>

#define N_MAX 100

void sort_rec(int A1[], int Tmp[], unsigned n) {
	unsigned i, j, h, k = n / 2;
	int *A2 = A1 + k;
	if (n < 2)
		return;
	sort_rec(A1, Tmp, k); //recursively sort left array
	sort_rec(A2, Tmp + k, n - k); //recursively sort right array
	//merge left and right array into temp buffer
	for (i = j = h = 0; i < n; i++) {
		if (h >= n - k || (j < k && A1[j] <= A2[h]))
			Tmp[i] = A1[j++];
		else
			Tmp[i] = A2[h++];
	}
	//copy from temp buffer to result array
	for (i = 0; i < n; i++)
		A1[i] = Tmp[i];
}

void sort(int A[], unsigned n) {
	int *Tmp = (int *) malloc(n * sizeof(int));
	sort_rec(A, Tmp, n);
	free(Tmp);
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
