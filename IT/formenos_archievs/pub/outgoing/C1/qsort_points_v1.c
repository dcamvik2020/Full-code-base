#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
} Point;

int cmp_func(const void *p1, const void *p2) {
	const Point *r1 = (const Point *)p1, *r2 = (const Point *)p2;
	int d1 = r1->x * r1->x + r1->y * r1->y;
	int d2 = r2->x * r2->x + r2->y * r2->y;
	if (d1 != d2)
		return d1 - d2;
	if (r1->x != r2->x)
		return r1->x - r2->x;
	return r1->y - r2->y;
}

int main(void) {
	int i, n;
	Point A[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %d", &A[i].x, &A[i].y);
	qsort(A, n, sizeof(Point), cmp_func);
	for (i = 0; i < n; i++)
		printf("%d %d\n", A[i].x, A[i].y);
	return 0;
}
