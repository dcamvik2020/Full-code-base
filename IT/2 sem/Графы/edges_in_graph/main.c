#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j, edges = 0;
    int a[100][100] = {{0}};
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (a[i][j] != a[j][i])
            {
                puts("-1");
                return 0;
            }
            edges += a[i][j];
        }
    }
    printf("%d\n", edges);
    return 0;
}
