#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x1, y1, x2, y2;
    double x3, y3, x4, y4;
    double vect_mult_1, vect_mult_2;
    double vect_mult_3, vect_mult_4;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    vect_mult_1 = (x4-x3)*(y1-y3)-(y4-y3)*(x1-x3);
    vect_mult_2 = (x4-x3)*(y2-y3)-(y4-y3)*(x2-x3);
    vect_mult_3 = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
    vect_mult_4 = (x2-x1)*(y4-y1)-(y2-y1)*(x4-x1);

    if (vect_mult_1 * vect_mult_2 > 0 || vect_mult_3 * vect_mult_4 > 0)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}
