#include <stdio.h>

int main(void)
{
    int j, max_0 = 0, n_max, i, N, a[1000000], len[100001] = {}, k = 0;
    scanf("%d", &N);
    for (i = N - 1; i >= 1; i--)
    {
        k = 0;
        for (j = 0; j < 1000000; j++)
        {
            a[j] = 0;
        }
        a[0] = i;
        while(a[k] > 1)
        {
            if (a[k] % 2 == 0)
                a[k + 1] = a[k] / 2;
            else
                a[k + 1] = 3 * a[k] + 1;
            k++;
        }
        len[i] = k + 1;
    }
    for (i = 1; i <= 100000; i++)
    {
        if (len[i] > max_0)
        {
            max_0 = len[i];
            n_max = i;
        }
    }
    printf("%d %d\n", n_max, max_0);
    return 0;
}

