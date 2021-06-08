#include <stdio.h>
#include <stdlib.h>

typedef struct dubolom dubolom;
struct dubolom {
    int indent;
    int height;
};

int cmp (int a[20000][2], int i, int j)
{
    /*int t;
    if (a[i][0] > a[j][0])
    {
        t = a[i][0];
        a[i][0] = a[j][0];
        a[j][0] = t;
        return 0;
    }*/
    return a[i][0] - a[j][0];
}

int main()
{
    int N, i;
    int a[20000][2];
    int x, max = -1, pred;
    scanf("%d", &N);
    qsort(a, N, 2 * sizeof(int) ,cmp);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &x);
        a[i][0] = x;
        if (a[i][0] > max)
        {
            pred = max;
            max = a[i][0];
        }
    }
    printf("%d  %d\n\n", max, pred);
    for (i = 0; i < N; i++)
        printf("%d ", a[i][0]);

    return 0;
}
