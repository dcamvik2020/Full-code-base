#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N, i;
    double a[1000];
    double m = 0, d = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%lf", &a[i]);
        m += a[i];
    }
    m /= N;
    for (i = 0; i < N; i++)
    {
        a[i] = (a[i] - m) * (a[i] - m);
        d += a[i];
    }
    d /= N;
    d = sqrt(d);
    printf("%lg %lg\n", m, d);
    return 0;
}
