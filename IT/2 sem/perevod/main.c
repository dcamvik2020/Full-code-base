#include <stdio.h>

int check_solution_comparations(int z[][3], int i, int j)
{
    int a = z[i][0], b = z[i][1], c = z[j][0], d = z[j][1];
    int t;
    for (t = 1; t <= d; t++)
    {
        if ((t*b+a-c) % d == 0)
        {
            if (j - i == 1)
                z[i][2] = t*b+a;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int a[8][3] = {{0}}, i, x, j;
    for (i = 0; i < 8; i++)
    {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    for (i = 0; i < 8; i++)
    {
        if (!a[i][1])
            continue;
        a[i][1] -= a[i][0];
        a[i][0] = a[i][0] % a[i][1];
        for (j = i + 1; j < 8; j++)
        {
            if (!check_solution_comparations(a, i, j))
            {
                printf("%d %d \n", i, j);
                puts("-1");
                return 0;
            }
        }
    }
    x = a[0][2];
    for (i = 2; i < 8; i++)
    {
        if (!a[i][1])
            continue;
        while (x % a[i][1] - a[i][0])
            x += a[0][1];
    }
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        puts("");
    }
    printf("%d\n", x);
    return 0;
}
