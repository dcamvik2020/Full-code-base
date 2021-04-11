#include <stdio.h>
#include <math.h>

///Geron's equation gives an uncorrect soltion on informatics.mmcme ...
///Obviously, there is some "delta" in results, if numbers are double type
int main()
{
    double x1, y1, x2, y2, x3, y3;
    ///double a, b, c;
    double square_triangle;///, half_perimetre;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    ///a = sqrtf((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    ///b = sqrtf((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
    ///c = sqrtf((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
    ///half_perimetre = (a + b + c) / 2;
    ///square_triangle = sqrtf(half_perimetre*(half_perimetre-a)*(half_perimetre-b)*(half_perimetre-c));
    square_triangle = fabs(0.5 * ((x1-x3)*(y2-y3)-(x2-x3)*(y1-y3)));
    printf("%.5lf\n", square_triangle);
    return 0;
}
