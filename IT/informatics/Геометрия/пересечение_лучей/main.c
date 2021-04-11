#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    double vect_mult, scal_mult;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    vect_mult = (x2-x1)*(y4-y3)-(y2-y1)*(x4-x3);
    scal_mult = (x2-x1)*(x4-x3)+(y2-y1)*(y4-y3);
    if (vect_mult == 0)
    {
        puts("NO");
        return 0;
    }
    if (scal_mult <)
    return 0;
}
