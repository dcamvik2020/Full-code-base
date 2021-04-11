#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j, deg = 0, x; /// deg, indeed, is not degree; it's quantity of incidents
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &x);
            if (j != i)
            {
                deg += x;
            }
        }
        if (deg % 2 == 1)
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
