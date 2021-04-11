#include <stdio.h>
#include <stdlib.h>

int main()
{
    int xa, ya, xb, yb, xc, yc;
    int vect_mult;
    scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);
    vect_mult = (xb-xa)*(yc-ya) - (yb-ya)*(xc-xa);
    if (vect_mult > 0)
    {
        puts("LEFT");
    }
    if (vect_mult < 0)
    {
        puts("LEFT");
    }
    if (vect_mult == 0)
    {
        puts("BOTH");
    }
    return 0;
}
