#include <stdio.h>
#include <stdlib.h>

#define cor0(x) ((x) > -1e-10 && (x) < 1e-10 ? 0 : (x))

int gauss_inversion(double **mtr_invert, int m)
{
    int i, j, k;
    double x;
    double *row;
    ///all under and over main diagonal = 0
    for (i = 0; i < m; i++) /// left->right
    {
        ///no null elements on main diagonal
        if (!cor0(mtr_invert[i][i]))
        {
            for (j = i + 1; j < m && !cor0(mtr_invert[j][i]); j++);
            if (j == m)
            {
                return 0;
            }
            row = mtr_invert[i];
            mtr_invert[i] = mtr_invert[j];
            mtr_invert[j] = row;
        }
        ///now mtr_invert[i][i] != 0 -> do it = 1
        x = mtr_invert[i][i];
        for (k = i; k < 2*m; k++)
        {
            mtr_invert[i][k] /= x;
        }
        ///now mtr_invert[i][i] = 1
        for (j = 0; j < m; j++)///up->down
        {
            if (j != i)
            {
                x = mtr_invert[j][i];
                for (k = i; k < 2*m; k++)
                {
                    mtr_invert[j][k] -= x*mtr_invert[i][k];
                }
                ///now mtr_invert[j][i] = 0
            }
        }
    }
    ///now all mtr_invert[i][i] = 1
    return 1;
}
int main()
{
    int m, i, j;
    double **mtr_invert;
    ///input
    scanf("%d", &m); ///size of matrix
    mtr_invert = (double**) malloc(m*sizeof(double*));
    for (i = 0; i < m; i++)
    {
        mtr_invert[i] = (double*) calloc(2*m, sizeof(double));
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%lf", &mtr_invert[i][j]);
        }
        mtr_invert[i][i + m] = 1;
    }
    ///serching inversion && output
    if (gauss_inversion(mtr_invert, m))
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < m; j++)
            {
                printf("%lg ", cor0(mtr_invert[i][m + j]));
            }
            puts("");
        }
    }
    else
    {
        puts("NO");
    }
    for (i = 0; i < m; i++)
    {
        free(mtr_invert[i]);
    }
    free(mtr_invert);
    return 0;
}
