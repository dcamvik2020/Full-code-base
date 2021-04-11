#include <stdio.h>

int A[1000][1000], a[1000], n, det = 0;

//the number of transgressions
int transgression(void) {
	int i, j, t = 0;
	//i < j, but ai > aj
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (a[i] > a[j])
				t++;
	return t;
}

//add conjunction to determinant
void sum(void) {
	int i, d = 1;
	//get conjunction A1i1 * A2i2 * ... * Anin
	for (i = 0; i < n; i++)
		d *= A[i][a[i]];
	//compute (-1)^N(i1, i2, ..., in)
	if (transgression() % 2)
		d = -d;
	det += d;
}

//recursive function generating permutations
void permutations(int l, int r) {
	int i, t;
	//permutation is ready
	if (l == r) {
		sum();
		return;
	}
	//enumerate all values left from a[l]
	for (i = l; i < r; i++) {
		t = a[l]; a[l] = a[i]; a[i] = t; //exchange
		permutations(l + 1, r); //recursion!
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
	permutations(0, n);
	printf("%d\n", det);
	return 0;
}
