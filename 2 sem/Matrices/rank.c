#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) > (b) ? (b) : (a))
#define cor0(x) (-1e-10 < (x) && (x) < 1e-10 ? 0 : (x))

int rank_matrix(double **mtr, int N, int M)
{
    int i, j, k, column;
    double *row, x;
    ///mtr -> step type of matrix
    for (i = 0, column = 0; i < N && column < M; column++)
    {
        if (!cor0(mtr[i][column]))
        {
            for (j = i + 1; j < N && !cor0(mtr[j][column]); j++);
            if (j == N)
            {
                continue;
            }
            row = mtr[j];
            mtr[j] = mtr[i];
            mtr[i] = row;
        }
        for (j = i + 1; j < N; j++)
        {
            x = mtr[j][column] / mtr[i][column];
            for (k = column; k < M; k++)
            {
                mtr[j][k] -= x*mtr[i][k];
            }
        }
        i++;
    }
    return i;
}

int main()
{
    int N, M, i, j;
    double **mtr;
    scanf("%d %d", &N, &M);
    mtr = (double **) malloc(N*sizeof(double*));
    for (i = 0; i < N; i++)
    {
        mtr[i] = (double *) malloc(M*sizeof(double));
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%lf", &mtr[i][j]);
        }
    }
    printf("%d\n", rank_matrix(mtr, N, M));
    for (i = 0; i < N; i++)
    {
        free(mtr[i]);
    }
    free(mtr);
    return 0;
}
