#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(unsigned*)a - *(unsigned*)b;
}

int main()
{
    unsigned *a = NULL, i = 0;
    int n, k;
    scanf("%u", &n);
    a = (unsigned*) malloc(n*sizeof(unsigned));
    for (; i < n; i++)
    {
        scanf("%u", &a[i]);
    }
    qsort(a, n, sizeof(unsigned), cmp);
    k = n - 2;
    while (k && a[n-1] < a[n-2] + a[k-1]) k--; /// min(k): a[k] + a[n-2] > a[n-1]
    if (k != n - 2)
    {
        puts("YES");
        printf("%u %u ", a[n-1], a[k]);
        for (i = 0; i < n-1; i++)
        {
            if (i != k) printf("%u ", a[i]);
        }
    }
    else puts("NO");
    free(a);
    return 0;
}
