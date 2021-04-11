#include <stdio.h>

//! ststic ���������� ����� ������� ���������, ������ �����, � ������� ��� �������
//!� ����� �����, ������ ������� ����� ����� ����������
//!����� �������, ����� ���������� � ����������� �������� ����������, ������������
//!��� ������� ������� �������

int sum_1_N (int N)
{
    static int prevArg = 1;
    static int prevSum = 1;
    int i;
    if (N == prevArg)
    {
        printf("old counting\n");
        return prevSum;
    }
    else
    {
        prevSum = 0;
        for (i = 1; i <= N; i++)
            prevSum += i;
        prevArg = N;
        printf("new counting: new_arg = %d\n", prevArg);
        return prevSum;
    }
}

//! returns all integers > 0
int next()
{
    static int counter = 0;
    counter++;
    return counter;
}

//! ������ �������� ����������� ���������� ������� �������, ������ ����������� �������������

int main(void) {
    int N;
    printf("sigma%d = %d\n", 10, sum_1_N(10));
    printf("sigma%d = %d\n", 10, sum_1_N(10));
    printf("sigma%d = %d\n\n\n", 11, sum_1_N(11));
    // your code goes here
    printf("%d\n", next());
    printf("%d\n", next());
    printf("%d\n", next());
    printf("%d\n", next());
    return 0;
}
