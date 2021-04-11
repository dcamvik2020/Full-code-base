#include <stdio.h>
#include <stdlib.h>

int N, K;
char s[21] = {0};

void rec(int n, int k)
{
    if (n == N)
    {
        puts(s);
        return;
    }
    if (n-k < N-K)
    {
        s[n] = '0';
        rec(n+1, k);
    }
    if (k < K)
    {
        s[n] = '1';
        rec(n+1, k+1);
    }
}

int main()
{
    scanf("%d %d", &N, &K);
    rec(0, 0);
    ///sometimes... recursion is much better than iterations
    ///because of time or even memory access
    /*int a[20] = {0}, i, j, p = 0;
    int N, K, schot = 0;
    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++)
    {
        if (i >= N - K)
            a[i] = 1;
        printf("%d", a[i]);
    }
    printf("\n");
    while(schot < N - K)
    {
        schot = 0;
        i = N - 1;
        while (!a[i] && i >= 0)
            i--;
        if (i == -1)
            break;
        while (a[i] && i > 0)
        {
            i--;
            schot++;
        }
        p = a[i];
        a[i] = a[i + 1];
        a[i + 1] = p;
        for (j = N - 1; j >= i + 1; j--)
        {
            if (j > N - schot)
                a[j] = 1;
            else
                a[j] = 0;
        }
        schot = 0;
        for (j = 0; j < N; j++)
            printf("%d", a[j]);
        printf("\n");
        for (j = N - 1; !a[j]; j--)
            schot++;
    }*/
    return 0;
}
