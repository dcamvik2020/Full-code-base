#include <stdio.h>

#define N_MAX 100

void sort(int A[], unsigned n) {
	int tmp;
	unsigned i, j, k;
	if (n >= 2) {
		if (A[0] > A[1]) {
			tmp = A[0];
			A[0] = A[1];
			A[1] = tmp;
		}
		//look for next item;
		//if it breaks the sorted part, insert it in the appropriate place
		for (i = 2; i < n; i++) {
			for (j = 0; j < i && A[j] < A[i]; j++);
			k = j; //A[i] must be between A[k-1] and A[k]
			tmp = A[i];
			//right shift array from k to i to insert chosen item
			for (j = i; j > k; j--)
				A[j] = A[j-1];
			A[k] = tmp;
		}
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
