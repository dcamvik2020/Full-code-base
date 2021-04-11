#include <stdio.h>

int main(void) {
	int i, n, A[100];
	int sumX(int m) {
		int i, res = 0;
		for (i = m; i < n; i++)
			res += A[i];
		return res;
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", A + i);
	printf("%d\n", sumX(3));
	return 0;
}
