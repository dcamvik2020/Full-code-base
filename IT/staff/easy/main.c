#include <stdio.h>
#include <stdlib.h>

/// ����� ����� ���������� ���������� �������, ���� �� ������ � ����� ���������� �������
/// ���������� �� ������� �������: X ������� -> X*2, X*3+1, X*4+3, X*5+6... �������� ���� (delta -> delta+1)
int main()
{
    int v, n, k = 0, j, delta; /// v - firstly destructed, n - all robots, k - all destructed robots
    unsigned char *a;
    scanf("%d %d", &v, &n);
    a = (unsigned char*) calloc((n >> 3) + 1, 1);
    for (; v; v--) /// numbers of destructed
    {
        scanf("%d", &delta);
        for (j = delta; j < n; j += delta, delta++)
        {
            a[j >> 3] |= 1 << (j & 7);
        }
    }
    for (j = 0; j < n; j++)
    {
        if (a[j >> 3] & (1 << (j & 7)))
            k++;
    }
    free(a);
    printf("%d\n", k);
    return 0;
}
