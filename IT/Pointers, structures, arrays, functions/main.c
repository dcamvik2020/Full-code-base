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
    x = y; /// переменные одного типа можно приравнивать
    printf("x: %d %d\ny: %d %d\n", x.a, x.b, y.a, y.b);

    int a[3] = {1, 3, 5};
    int b[3] = {2, 4, 6};
    int * const A = a, B; /// изменение указателя не скомпилируется, нельзя менять постоянный указатель
    int const * C = 5;    /// изменение значения  не скомпилируется
    int *D;

    ///int X[10];            /// we can't even "repeat"
    ///int * const Y = X;    /// initialisation if we used
    ///Y = X;                /// type * const ...


    ///указатели
    ///A = NULL;  так писать нельзя
    ///*C = 6;    compilation error
    ///*(A+1)=2;  а вот так можно писать

    ///массивы
    ///D[5] = 5;  runtime error
    ///a = b; /// compilation error  : a,b -> adresses (constants), -> we can't mov in a number another number
    func1(a, b);                                /// То есть, т.к. в функции передаются массивы по указателю,
    printf("%d %d %d\n", a[0], a[1], a[2]);     /// элементы массива можно менять внутри функции, сами же
    printf("%d %d %d\n\n", b[0], b[1], b[2]);   /// указатели по выходу из функции "возвращают" прежние значения


    ///структуры
    st x = {1, 3};
    st y = {2, 4};
    func2(x, y);                                /// Стурктуры копируются в функции полностью, поэтому
    printf("%d %d\n", x.a, x.b);                /// все изменения остаются внутри функции, а структуры своего
    printf("%d %d\n", y.a, y.b);                /// значения, по факту не меняют. Это же касается массивов
                                                /// переданных через структуру - скопируются сами массивы,
                                                /// а не их указатель.


   printf("%\n\n%d\n", sizeof("Hello\n"));
    ///nbits(1);

    return 0;
}
