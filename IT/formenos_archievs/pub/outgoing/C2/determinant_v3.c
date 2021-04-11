#include <stdio.h>

int A[1000][1000], a[1000], n, det = 0;

//add conjunction to determinant
void sum(int d) {
	int i;
	//get conjunction A1i1 * A2i2 * ... * Anin
	for (i = 0; i < n; i++)
		d *= A[i][a[i]];
	det += d;
}

//recursive function generating permutations
void permutations(int l, int r, int sg) {
	int i, t;
	//permutation is ready
	if (l == r) {
		sum(sg);
		return;
	}
	//enumerate all values left from a[l]
	for (i = l; i < r; i++) {
		t = a[l]; a[l] = a[i]; a[i] = t; //exchange
		//every transgression change parity of permutation, so change sign of "sg"
		permutations(l + 1, r, i == l ? sg : -sg); //recursion!
		t = a[l]; a[l] = a[i]; a[i] = t; //restore back
	}
}

int main(void) {
	int i, j;
	//input data
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	//init
	for (i = 0; i < n; i++)
		a[i] = i;
	permutations(0, n, 1);
	printf("%d\n", det);
	return 0;
}
