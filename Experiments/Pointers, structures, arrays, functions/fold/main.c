#include <stdio.h>
#include <string.h>

typedef struct {
    int a;
    int b;
} st;

void func1(int a[3], int b[3]) {
    a = b;
    a[0] = b[2];
}

void func2(st x, st y) {
    x.a = y.b;
}

void nbits(float x)
{
    int res;
    for (x = 1, res = 0; x; x /= 2, res++);
    printf("%d\n", res);
}

int main()
{
    st x = {1, 2}, y = {3, 4};
    x = y; /// ���������� ������ ���� ����� ������������
    printf("x: %d %d\ny: %d %d\n", x.a, x.b, y.a, y.b);

    int a[3] = {1, 3, 5};
    int b[3] = {2, 4, 6};
    int * const A = a, B; /// ��������� ��������� �� ��������������, ������ ������ ���������� ���������
    int const * C = 5;    /// ��������� ��������  �� ��������������
    int *D;

    ///int X[10];            /// we can't even "repeat"
    ///int * const Y = X;    /// initialisation if we used
    ///Y = X;                /// type * const ...


    ///���������
    ///A = NULL;  ��� ������ ������
    ///*C = 6;    compilation error
    ///*(A+1)=2;  � ��� ��� ����� ������

    ///�������
    ///D[5] = 5;  runtime error
    ///a = b; /// compilation error  : a,b -> adresses (constants), -> we can't mov in a number another number
    func1(a, b);                                /// �� ����, �.�. � ������� ���������� ������� �� ���������,
    printf("%d %d %d\n", a[0], a[1], a[2]);     /// �������� ������� ����� ������ ������ �������, ���� ��
    printf("%d %d %d\n\n", b[0], b[1], b[2]);   /// ��������� �� ������ �� ������� "����������" ������� ��������


    ///���������
    st x = {1, 3};
    st y = {2, 4};
    func2(x, y);                                /// ��������� ���������� � ������� ���������, �������
    printf("%d %d\n", x.a, x.b);                /// ��� ��������� �������� ������ �������, � ��������� ������
    printf("%d %d\n", y.a, y.b);                /// ��������, �� ����� �� ������. ��� �� �������� ��������
                                                /// ���������� ����� ��������� - ����������� ���� �������,
                                                /// � �� �� ���������.


   printf("%\n\n%d\n", sizeof("Hello\n"));
    ///nbits(1);

    return 0;
}
