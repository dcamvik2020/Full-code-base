#include <stdio.h>
#include <math.h>


/// 4 tests
int main()
{
    double x0, y0; /// point
    double x1, y1, x2, y2; /// start, end of vector
    double dist, len;
    scanf("%lf %lf %lf %lf %lf %lf", &x0, &y0, &x1, &y1, &x2, &y2);
    if (((x2 - x1)*(x0 - x1) + (y2 - y1)*(y0 - y1)) <= 0)
    {
        dist = sqrtf((y0 - y1)*(y0 - y1) + (x0 - x1)*(x0 - x1));
        printf("%lf\n", dist);
        return 0;
    }
    if (((x2 - x1)*(x2 - x0) + (y2 - y1)*(y2 - y0)) <= 0)
    {
        dist = sqrtf((y0 - y2)*(y0 - y2) + (x0 - x2)*(x0 - x2));
        printf("%lf\n", dist);
        return 0;
    }
    len = sqrtf((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1));
    dist = ((x2 - x1)*(y0 - y1) - (y2 - y1)*(x0 - x1)) / len;
    printf("%lf\n", fabs(dist));
    return 0;
}
