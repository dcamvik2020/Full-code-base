#include <stdio.h>

double f(int n, double a, double x, double x_0);
double step(int n, double a);
int main(void)
{
    int n;
    double a, x0 = 1, y;
    scanf("%d %lf", &n, &a);
    if (a == 0)
    {
        puts("0");
        return 0;
    }
    y = f(n , a, x0, x0);
    printf("%lf", y);
    return 0;
}

double step(int n, double a)
{
    double y = 1;
    while (n > 0)
    {
        y *= a;
        n--;
    }
    return y;
}

double f(int n, double a, double x, double x_0)
{
    x_0 = x;
    x = (x * (n - 1) + a / step(n - 1, x)) / n;
    if (x - x_0 < 0.0001 && x - x_0 > -0.0001)
        return x;
    return f(n, a, x, x_0);
}
