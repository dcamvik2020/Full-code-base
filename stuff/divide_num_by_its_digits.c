#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, i, x, flag;
    scanf("%d %d", &a, &b);
    for (i = a; i <= b; i++)
    {
        flag = 1;
        x = i;
        while (x > 0)
        {
            if (x%10==0 || i % (x%10) != 0)
            {
                flag = 0;
                break;
            }
            x /= 10;
        }
        if (flag == 0) continue;
        else printf("%d ", i);
    }
    puts("");
    return 0;
}
