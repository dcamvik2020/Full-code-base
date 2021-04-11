#include <stdio.h>
#include <stdlib.h>

///we have to sort an array of 0 < N <= 1000 int points (int x, int y) by the distance from (0, 0)
///if d(1) == d(2) -> sort by x(1), x(2)
///if x(1) == x(2) -> sort by y(1), y(2)

typedef struct Point {
    int x;
    int y;
} P;

int cmp(const void *a, const void *b)
{
    P *A = (P*) a, *B = (P*) b;
    int d1 = A->x * A->x + A->y * A->y;
    int d2 = B->x * B->x + B->y * B->y;
    if (d1 != d2)
        return d1 - d2;
    if (A->x != B->x)
        return A->x - B->x;
    return A->y - B->y;
}

int main()
{
    int N, i = 0;
    P *points = NULL;
    scanf("%d", &N);
    points = (P*) malloc(N*sizeof(P));
    for (; i < N; i++)
        scanf("%d %d", &points[i].x, &points[i].y);
    qsort(points, N, sizeof(P), cmp);
    for (i = 0; i < N; i++)
        printf("%d %d\n", points[i].x, points[i].y);
    free(points);
    return 0;
}
