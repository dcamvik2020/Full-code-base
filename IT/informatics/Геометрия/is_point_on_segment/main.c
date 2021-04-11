#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x, y;
    double x1, y1, x2, y2;
    double vect_mult, scal_mult;
    scanf("%lf %lf %lf %lf %lf %lf", &x, &y, &x1, &y1, &x2, &y2);
    vect_mult = (x-x1)*(y-y2)-(y-y1)*(x-x2);
    scal_mult = (x-x1)*(x-x2)+(y-y1)*(y-y2);
    if (vect_mult != 0 || scal_mult > 0)
    {
        puts("NO");
    }
    else
    {
        puts("YES");
    }
    return 0;
}
