#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct str str;
struct str {
    char s[101];
    int len;
};

int cmp(str *A, int i, int j)
{
    int k;
    if (A[i].len < A[j].len)
        return 0;
    if (A[i].len < A[j].len)
        return 1;
    for (k = A[i].len - 1; k >= 0; k--)
    {
        if (A[i].s[k] < A[j].s[k])
            return 0;
    }
    return 1;
}

int main()
{
    int N, i;
    char pp;
    str *A = (str *) malloc(sizeof(str *));
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        gets(pp);
        A[i].s = pp;
        A[i].len = strlen(pp);
    }
    qsort(A, N, sizeof(str), cmp);
    return 0;
}
