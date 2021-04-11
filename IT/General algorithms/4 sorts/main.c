#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubble (int a[40], int N);
void inserts (int a[40], int N);
void merge (int a[40], int l, int r);
void my_qsort (int a[40], int l, int r);
int main(void) {
    int a[40];
    int i, N;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    //bubble(a, N);
    //inserts(a, N);
    //merge(a, 0, N-1);
    my_qsort(a, 0, N-1);
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    puts("");
    return 0;
}

void bubble (int a[40], int N)
{
    int i, j, t;
    for (i = 0; i < N; i++)
        for (j = 0; j < N - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
}

void inserts (int a[40], int N)
{
    int amin, imin, t, i, j;
    for (i = 0; i < N; i++)
    {
        amin = a[i];
        imin = i;
        for (j = i; j < N; j++)
        {
            if (amin > a[j])
            {
                amin = a[j];
                imin = j;
            }
        }
        t = a[imin];
        a[imin] = a[i];
        a[i] = t;
    }
}

void merge(int a[40], int l, int r) // increasing ->
{
    int b[20], c[20];
    int N, i, j, x, y, p;
    int mid = (l + r) / 2;
    if (l == r) return;
    if (r == l + 1)
    {
        if (a[l] > a[r])
        {
            p = a[l];
            a[l] = a[r];
            a[r] = p;
        }
        return;
    }
    merge(a, l, mid);
    merge(a, mid + 1, r);
    x = mid - l + 1; // quantinty of elemetns in b[20]
    y = r - mid; // quantinty of elemetns in c[20]
    for (i = 0; i < x; i++) b[i] = a[i + l];
    for (i = 0; i < y; i++) c[i] = a[i + mid + 1];
    i = 0; j = 0; N = 0;
    while (i < x || j < y)
    {
        if (i == x)
        {
            a[N + l] = c[j];
            j++;
            N++;
            continue;
        }
        if (j == y)
        {
            a[N + l] = b[i];
            i++;
            N++;
            continue;
        }
        if (b[i] < c[j])
        {
            a[N + l] = b[i];
            i++;
        }
        else
        {
            a[N + l] = c[j];
            j++;
        }
        N++;
    }
}

void my_qsort (int a[40], int l, int r)
{
    int mid = (l + r) / 2;
    int i = l, j = r, p;
    int x = a[mid];
    if (l == r) return;
    if (r == l + 1)
    {
        if (a[l] > a[r])
        {
            p = a[l];
            a[l] = a[r];
            a[r] = p;
        }
        return;
    }
    while (i < j)
    {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i < j)
        {
            if (mid == i) mid = j;
            else
            {
                if (mid == j)
                {
                    mid = i;
                }
            }
            p = a[i];
            a[i] = a[j];
            a[j] = p;
        }
    }
    my_qsort(a, l, mid);
    my_qsort(a, mid, r);
}
