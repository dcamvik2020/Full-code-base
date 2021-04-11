#include <stdio.h>

int main(void) {
	int x1, x2, p, q;
	scanf("%d %d", &x1, &x2);
	p = -(x1 + x2);
	q = x1 * x2;
	printf("x^2 ");
	if (p) {
		printf("%c ", p > 0 ? '+' : '-');
		if (p != 1 && p != -1)
			printf("%d", p > 0 ? p : -p);
		printf("x ");
	}
	if (q)
		printf("%c %d ", q > 0 ? '+' : '-', q > 0 ? q : -q);
	printf("= 0\n");
	return 0;
}
