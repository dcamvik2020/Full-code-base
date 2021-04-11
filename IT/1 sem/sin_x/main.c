#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000

double f_sin(double x)
{
    int i;
    double sum = 0, f = x;
    for (i = 2; i < N; i += 2)
    {
        sum += f;
        f *= -x * x /(i * (i + 1));
    }
    return sum;
}

int main(void)
{
    double x;
    scanf("%lf", &x);
    x = (int)x % 360;
    x *= M_PI / 180;
    printf("%lg\n", f_sin(x));
    return 0;
}
