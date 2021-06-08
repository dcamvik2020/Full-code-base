#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
    return;
}

void q_sort(int a[100], int l, int r)
{
    if (l == r)
    {
        return;
    }
    if (l + 1 == r)
    {
        if (a[l] < a[r])
        {
            swap(&a[l], &a[r]);
        }
        return;
    }
    int mid = (l + r) / 2;
    int i = l, j = r;
    while (i < j)
    {
        while (a[i] > a[mid])
        {
            i++;
        }
        while (a[mid] > a[j])
        {
            j--;
        } // i want to sort it decreasing ->

        swap(&a[i], &a[j]);
    }
    q_sort(a, l, mid);
    q_sort(a, mid, r);
}

int main()
{
    int a[100], i, N;
    scanf("%d", &N);
    srand(time(NULL));
    for (i = 0; i < N; i++)
    {
        a[i] = rand();
    }
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    puts("");
    q_sort(a, 0, N - 1);
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    return 0;
}


