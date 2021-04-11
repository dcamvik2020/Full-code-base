#include <iostream>

#include "Complex.h"
#include "Matrix.h"

/*
int main() {
    Matrix<Complex> A;
    cout << "Matrix A:" << endl;
    cin >> A;
    Matrix<Complex> B = A.inversed();
    cout << "\nB = inversed(A):" << endl;
    cout << B << endl;

    Matrix<Complex> C = A * B;
    C.MakeAccuracy();
    cout << "\nA * B:" << endl;
    cout << C << endl;
    return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>

#define correct_0(x) (-1e-10 < (x) && (x) < 1e-10 ? 0 : (x))

/// m - size of mtr, i - row, j - column
void get_matrix(int **mtr, int m, int **p, int i, int j)
{
    int a, b, dx, dy;
    dy = 0;
    for (a = 0; a < m-1; a++)
    {
        dx = 0;
        if (a == i)
            dy = 1;
        for (b = 0; b < m-1; b++)
        {
            if (b == j)
                dx = 1;
            p[a][b] = mtr[a+dy][b+dx];
        }
    }
}

int determinant(int **mtr, int m)
{
    int d = 0, k = 1; /// (-1)^n
    int **p;
    int i;
    if (m < 1)
        puts("Error size of matrix");
    if (m == 1)
        return mtr[0][0];
    p = (int**) malloc((m-1)*sizeof(int*));
    for (i = 0; i < m-1; i++)
        p[i] = (int*) malloc((m-1)*sizeof(int));
    for (i = 0; i < m; i++)
    {
        get_matrix(mtr, m, p, 0, i);
        d += k * mtr[0][i] * determinant(p, m-1);
        k = -k;
    }
    for (i = 0; i < m-1; i++)
        free(p[i]);
    free(p);
    return d;
}

void change_column(int **mtr, int N, int j)
{
    int *t;
    if (j == 0)
    {
        t = mtr[N];
        mtr[N] = mtr[j];
        mtr[j] = t;
        return;
    }
    t = mtr[N];
    mtr[N] = mtr[j];
    mtr[j] = mtr[j-1];
    mtr[j-1] = t;
}

int main()
{
    int N, i, j;
    int **numbers, x0;
    double x;
    scanf("%d", &N);
    numbers = (int **) malloc((N+1)*sizeof(int*));
    for (i = 0; i <= N; i++)
    {
        numbers[i] = (int *) malloc(N*sizeof(int));
    }
    ///input
    for (i = 0; i < N; i++)
    {
        for (j = 0; j <= N; j++)
        {
            scanf("%d", &numbers[j][i]);
        }
    }
    ///check and the search of solutions
    x0 = determinant(numbers, N);
    if (x0)
    {
        for (i = 0; i < N; i++)
        {
            change_column(numbers, N, i);
            x = (double) determinant(numbers, N) / x0;
            printf("%lg\n", correct_0(x));
        }
    }
    else
    {
        puts("NO");
    }
    for (i = 0; i <= N; i++)
    {
        free(numbers[i]);
    }
    free(numbers);
    return 0;
}

