#include <stdio.h>
#include <math.h>

///equation of tg(x)=x in [a;b] = ?
///at [a;b] f(x)=tg(x) is continuous(uninterrupted)

#define eps 1e-11

int k = 0;
double equ(double a, double b)
{
    double mid;
    if (tan(b) < b || tan(a) > a) return -1;
    for (; b-a > 2*eps; k++)
    {
        mid = (a + b) / 2;
        if (tan(mid) > mid) b = mid;
        else a = mid;
    }
    return mid;
}

int main(void) {
    double a, b, x;
    int i = 0;
    for (; i < 39; i++) {
        scanf("%lf %lf", &a, &b);
        x = equ(a, b);
        printf("solution: %.10lf\n", x);
    }//if(x != -1) printf("%d\n", k);
    return 0;
}
