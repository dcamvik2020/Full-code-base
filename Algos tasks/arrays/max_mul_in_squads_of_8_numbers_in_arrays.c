#include <stdio.h>

/// �� ���� ����� a_1, a_2, ... , a_n. �� ��� ����� ����� max_mul(a_i * a_j):
/// |i - j| < 8; + ���� ����� O(1) ������. ������ ��������. �����, ����� ��������� ����.
/// !!!!!! i = j ���� �������� !!!!!!
int main()
{
    int a[8] = {0}, max_mul = 0, i, x, y;
    do {
        for (i = 0; i < 7; i++)
        {
            a[i] = a[i + 1];
        }
        scanf("%d", a + 7);
        for (i = 0; i < 8; i++)
        {
            if (a[i] * a[7] > max_mul)
            {
                max_mul = a[i] * a[7];
                x = a[i], y = a[7];
            }
        }
    } while(a[7]);
    printf("%d\nx=%d  y=%d", max_mul, x, y);
    return 0;
}
