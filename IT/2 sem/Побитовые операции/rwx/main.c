#include <stdio.h>

void f(int x) /// x is a digit from 0 to 7
{
    if (x & 4)
        putchar('r');
    else
        putchar('-');
    if (x & 2)
        putchar('w');
    else
        putchar('-');
    if (x & 1)
        putchar('x');
    else
        putchar('-');
}

int main()
{
    char d[4];
    scanf("%s", d);
    f(d[0] - '0');
    f(d[1] - '0');
    f(d[2] - '0');
    return 0;
}
