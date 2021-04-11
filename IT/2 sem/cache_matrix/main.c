#include <stdio.h>

int NOD(int a, int b)
{
    while (b)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int check_mult_matrix(int A[1024][1024], int B[1024][1024], int d, int n)
{
    int k = 0, x, i, j, l;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            x = 0;
            for (l = 0; l < n; l++)
            {
                x += A[i][l] * B[j][l];
            }
            if (!(x % d))
                k++;
        }
    }
    return k;
}

int A[1024][1024], B[1024][1024];
int main()
{
    int n, d, i, j;
    scanf("%d %d", &n, &d);
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            A[j][i] = A[i][j] = NOD(i+1, j+1);
            B[j][i] = B[i][j] = NOD(n-i+1, n-j+1);
        }
    }
    printf("%d\n", check_mult_matrix(A, B, d, n));
    return 0;
}
