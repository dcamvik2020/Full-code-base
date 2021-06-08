#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x0, y0; /// point
    double x1, y1, x2, y2; /// start, end of vector
    scanf("%lf %lf %lf %lf %lf %lf", &x0, &y0, &x1, &y1, &x2, &y2);
    if ((x2 - x1)*(x0 - x1) + (y2 - y1)*(y0 - y1) >= 0 && pow((x2 - x1)*(x0 - x1) + (y2 - y1)*(y0 - y1), 2) == ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) * ((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1)))
        puts("YES");
    else
        puts("NO");
    return 0;
}
