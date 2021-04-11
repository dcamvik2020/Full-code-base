#include <stdio.h>

#define max(a, b) ((a) >= (b) ? (a) : (b))

int check_solution_comparations(int z[][2], int i, int j)
{
    int t, a = z[i][0] % z[i][1], b = z[i][1], c = z[j][0] % z[j][1], d = z[j][1];
    for (t = 0; t < d; t++)
    {
        if (!((t*b + a - c) % d))
            return 1;
    }
    return 0;
}

int main()
{
    int a[8][2] = {{0}}, i, x = 0, j;
    for (i = 0; i < 8; i++)
    {
        scanf("%d %d", &a[i][0], &a[i][1]);
        a[i][1] -= a[i][0];
    }
    ///check existence of the solution
    for (i = 0; i < 8; i++)
    {
        if (a[i][1])
        {
            for (j = i + 1; j < 8; j++)
            {
                if (a[j][1] && !check_solution_comparations(a, i, j))
                {
                    puts("-1");
                    return 0;
                }
            }
        }
    }
    ///search of the solution
    x = a[0][0] + a[0][1];
    for (i = 1; i < 8; i++)
    {
        if (a[i][1])
        {
            while ((x - a[i][0]) % a[i][1] || x < a[i][0] + a[i][1])
                x += a[0][1];
        }
    }
    printf("%d\n", x);
    return 0;
}
