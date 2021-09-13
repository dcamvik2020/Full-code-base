#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define g 9.8

int main()
{
    double h, t, t0;
    int k = 0;
    scanf("%lf %lf", &h, &t);
    t0 = sqrt(2 * h / g);
    if (h == 0)
    {
        puts("0");
        return 0;
    }
    k = (int)(t / t0);
    t -= k * t0;
    if (k % 2 == 1)
        h = sqrt(2* g * h) * t - g * t * t / 2;
    else
        h = h - g * t * t / 2;
    printf("%lg\n", h);
    return 0;
}
