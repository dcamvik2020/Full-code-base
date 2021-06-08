#include <stdio.h>

#define maxim(a, b) ((a) >= (b) ? (a):(b))

int main(void)
{
    int N, i, j;
    int a[101][101] = {{0}};
    int sum_0 = 0;
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= i; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= i; j++)
        {
            a[i][j] += maxim(a[i - 1][j], a[i - 1][j - 1]);
        }
    }
    for (i = 1; i <= N; ++i)
    {
        if (a[N][i] > sum_0)
        {
            sum_0 = a[N][i];
        }
    }
    printf("%d\n", sum_0);
    return 0;
}
