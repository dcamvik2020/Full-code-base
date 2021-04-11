#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int i, j, n, m, A[100][100];
	char s[4096], t[4096], *p;
	for (n = 0; fgets(s, sizeof s, stdin); n++) {
		for (m = 0, p = s; sscanf(p, "%s", t) == 1; m++, p = strstr(p, t) + strlen(t))
			A[n][m] = atoi(t);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
	return 0;
}
