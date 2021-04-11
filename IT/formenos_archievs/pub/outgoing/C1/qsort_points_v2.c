#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
	int r;
} Point;

int cmp_func(const void *p1, const void *p2) {
	const Point *r1 = (const Point *)p1, *r2 = (const Point *)p2;
	if (r1->r != r2->r)
		return r1->r - r2->r;
	if (r1->x != r2->x)
		return r1->x - r2->x;
	return r1->y - r2->y;
}

int main(void) {
	int i, n;
	Point A[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &A[i].x, &A[i].y);
		A[i].r = A[i].x * A[i].x + A[i].y * A[i].y;
	}
	qsort(A, n, sizeof(Point), cmp_func);
	for (i = 0; i < n; i++)
		printf("%d %d\n", A[i].x, A[i].y);
	return 0;
}
