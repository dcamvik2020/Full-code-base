#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b, c, d;
    scanf("%d%di %d%di", &a, &b, &c, &d);
    printf("%d%+di\n", a*c - b*d, b*c + a*d);
    return 0;
}
