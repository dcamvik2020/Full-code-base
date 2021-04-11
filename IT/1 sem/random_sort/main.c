#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void q_sort(int *a, unsigned n)
{
    unsigned l = 0, r = n - 1;
    int x;
    if (n < 2)
        return;
    x = a[n / 2];
    while (l < r)
    {
        while (a[l] > x)
            l++;
        while (x > a[r])
            r--;  /// i want to sort it increasing <-
        if (l <= r)
        {
            swap(&a[l], &a[r]);
            l++;
            r--;
        }
    }
    q_sort(a, r + 1);
    q_sort(a + l, n - l);
}

int main()
{
    int *a, i, N;
    scanf("%d", &N);
    srand((unsigned)time(NULL)); /// возвращаем через return
    a = (int *) malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
        a[i] = rand();
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    puts("");
    q_sort(a, N);
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    free(a);
    printf("\n%d\n", -10 % 3);
    return 0;
}
