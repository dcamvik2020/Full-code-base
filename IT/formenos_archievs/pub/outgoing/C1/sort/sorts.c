void selection(int A[], unsigned n) {
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

void bubble(int A[], unsigned n) {
	unsigned i, j;
	for (i = n - 1; i >= 1; i--)
		for (j = 0; j < i; j++)
			//exchange every two unsorted neighbors
			if (A[j] > A[j+1]) {
				int tmp = A[j];
				A[j] = A[j+1];
				A[j+1] = tmp;
			}
}

void bubble2(int A[], unsigned n) {
	unsigned i, j, bFlag = 1;
	for (i = n - 1; i >= 1 && bFlag; i--) {
		bFlag = 0;
		for (j = 0; j < i; j++)
			//exchange every two unsorted neighbors
			if (A[j] > A[j+1]) {
				int tmp = A[j];
				A[j] = A[j+1];
				A[j+1] = tmp;
				bFlag = 1;
			}
	}
}

void insertion(int A[], unsigned n) {
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

void quicksort(int A[], unsigned n) {
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
	quicksort(A, r + 1); //recursively sort left array
	quicksort(A + l, n - l); //recursively sort right array
}

void merge_rec(int A1[], int Tmp[], unsigned n) {
	unsigned i, j, h, k = n / 2;
	int *A2 = A1 + k;
	if (n < 2)
		return;
	merge_rec(A1, Tmp, k); //recursively sort left array
	merge_rec(A2, Tmp + k, n - k); //recursively sort right array
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

#include <stdlib.h>

void merge(int A[], unsigned n) {
	int *Tmp = (int *) malloc(n * sizeof(int));
	merge_rec(A, Tmp, n);
	free(Tmp);
}
