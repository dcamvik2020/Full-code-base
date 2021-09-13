#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define dx 1e-4

int main()
{
    double a, b, sum = 0, t = 1, x;
    scanf("%lf %lf", &a, &b);
    a *= M_PI / 180;
    b *= M_PI / 180;
    if (b < a)
    {
        t = a;
        a = b;
        b = t;
        t = -1;
    }
    for (x = a; x < b; x += dx)
    {
        sum += dx * (cos(x * x) + cos((x + dx) * (x + dx))) / 2;
    }
    printf("%lg\n", sum * t);
    return 0;
}
