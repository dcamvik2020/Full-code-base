#include <stdio.h>

unsigned int deg(unsigned int *x)
{
    unsigned int n = 1;
    while (!(*x & 1))
    {
        *x >>= 1;
        n <<= 1;
    }
    return n;
}

int main()
{
    unsigned int x, n, t;
    scanf("%u", &x);
    n = deg(&x);
    t = --x;
    if (x && t == deg(&x))
        printf("%u %u\n", t, n);
    else
        puts("-1");
    return 0;
}
