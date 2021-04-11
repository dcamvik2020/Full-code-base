#include <stdio.h>

#define N_MAX 100

void sort(int A[], unsigned n) {
	unsigned l = 0, r = n - 1;
	int x;
	if (n < 2)
		return;
	x = A[n/2];
	//divide on 2 parts: less and greater x
	while (l < r) {
		//pass elements
		while (A[l] < x)
			l++;
		while (A[r] > x)
			r--;
		//swap
		if (l <= r) {
			int tmp = A[l];
			A[l] = A[r];
			A[r] = tmp;
			l++; r--;
		}
	}
	sort(A, r + 1); //recursively sort left array
	sort(A + l, n - l); //recursively sort right array
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
