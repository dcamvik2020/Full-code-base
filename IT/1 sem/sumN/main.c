#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int sumN(unsigned n, ...)
{
    int sum = 0;
    va_list v;
    va_start(v, n);
    while (n--)
        sum += va_arg(v, int);
    va_end(v);
    return sum;
}

int main()
{
    int N;
    scanf("%d", &N);
    printf("%d\n", sumN(2, 1, 2));
    return 0;
}
