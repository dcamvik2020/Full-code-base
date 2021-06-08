#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a, b, c;
    double d, x1, x2, t;
    scanf("%lf %lf %lf", &a, &b, &c);
    d = b * b - 4 * a * c;
    if (d < 0)
    {
        puts("NO");
        return 0;
    }
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                puts("R");
            }
            else
            {
                puts("NO");
            }
        }
        else
        {
            if (c == 0)
            {
                printf("%lf", 0);
            }
            else
            {
                printf("%+lf\n", -c / b);
            }
        }
    }
    else
    {
        if (d == 0)
        {
            if (c == 0)
            {
                printf("%lf", 0);
            }
            else
            {
                printf("%lf\n", -b/(2*a));
            }
        }
        else
        {
            x1 = (-b - sqrt(d))/(2*a);
            x2 = (-b + sqrt(d))/(2*a);
            if (x1 > x2)
            {
                t = x1;
                x1 = x2;
                x2 = t;
            }
            printf("%lf %lf\n", x1, x2);
        }
    }
    return 0;
}
