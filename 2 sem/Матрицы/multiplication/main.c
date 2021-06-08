#include <stdio.h>
#include <stdlib.h>

void multipl_2_mtr(double **A, int n, int m, double **B, int x, int y, double **C)
{
    int i = 0, j = 0, k;
    for (; i < n; j++)
    {
        if (j == y)
        {
            j = -1; ///after "continue" will be made j++, -> -1+1=0
            i++;
            continue;
        }
        for (k = 0; k < m; k++)
        {
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}

int main()
{
    double **A, **B, **C;
    int n, m, x, y;
    int i, j;

    ///input(sizes)
    puts("Choose size of A:");
    scanf("%d %d", &n, &m);
    puts("\nChoose size of B:");
    scanf("%d %d", &x, &y);

    ///check of existance of the result
    if (m != x)
    {
        puts("The multiplication can't be done  :(");
        return 0;
    }
    puts("\nOK. Sizes are right.");

    ///malloc and input(matrixes)
    puts("\nFill in the numbers in A:");
    A = (double **) malloc(n * sizeof(double *));
    for (i = 0; i < n; i++)
    {
        A[i] = (double *) malloc(m * sizeof(double));
        for (j = 0; j < m; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }
    puts("\nFill in the numbers in B:");
    B = (double **) malloc(x * sizeof(double *));
    for (i = 0; i < x; i++)
    {
        B[i] = (double *) malloc(y * sizeof(double));
        for (j = 0; j < y; j++)
        {
            scanf("%lf", &B[i][j]);
        }
    }
    C = (double **) malloc(n * sizeof(double *));
    for (i = 0; i < x; i++)
    {
        C[i] = (double *) calloc(y, sizeof(double));
    }

    ///multiplication
    multipl_2_mtr(A, n, m, B, x, y, C);

    ///output
    puts("\nThe result is C:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("%lg ", C[i][j]);
        }
        puts("");
    }
    return 0;
}
