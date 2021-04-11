
// j = position, x <= 3 <-> quantity of NOT NULL, k = quantity of already NULLs
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, i, j = 0, x;
    char a[100001];
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
    {
        a[i] = 1;
    }
    for (i = 0; i < N; i++)
    {
        for (x = 0; x < M; j++)
        {
            if (a[j % N] == 1)
            {
                x++;
            }
        }
        a[(j - 1) % N] = 0;
        if (i >= N - 3)
        {
            printf("%d ", (j - 1) % N + 1);
        }
    }
    return 0;
}
