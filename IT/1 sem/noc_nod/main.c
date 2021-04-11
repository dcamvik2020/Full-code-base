#include <stdio.h>
#include <stdlib.h>

int f_nod(int a, int b);
int main(void)
{
    int N, x, noc, nod, nod_of_noc_and_x;
    scanf("%d", &N);
    scanf("%d", &x);
    N--;
    noc = x;
    nod = x;
    while (N > 0)
    {
        scanf("%d", &x);
        N--;
        nod = f_nod(nod, x);
        nod_of_noc_and_x = f_nod(x, noc);
        noc = noc * x / nod_of_noc_and_x;
    }
    printf("%d %d", nod, noc);
}

int f_nod(int a, int b)
{
    if (b == 0)
        return a;
    if (a < b)
        return f_nod(a, b % a);
    return f_nod(b, a % b);
}
