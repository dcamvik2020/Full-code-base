#include <stdio.h>
#include <stdlib.h>

int step(int a, int k)
{
    int x = 1;
    while (k > 0)
    {
        x *= a;
        k--;
    }
    return x;
}
int main()
{
    int a, b, i, j, k, x, flag = 0, sum;
    scanf("%d %d", &a, &b);
    for (i = a; i <= b; i++)
    {
        x = i;
        k = 0;
        sum = 0;
        while (x > 0)
        {
            x /= 10;
            k++;
        }
        x = i;
        for (j = 1; j <= k; j++)
        {
            sum += step(x%10, k);
            x /= 10;
        }
        if (i == sum)
        {
            flag = 1;
            printf("%d ", i);
        }
    }
    if (flag == 0)
    {
        puts("-1");
    }
    return 0;
}
