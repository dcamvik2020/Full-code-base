#include <stdio.h>
#include <math.h>

#define N 100

int main(void)
{
	int i, j, n, A[N];
	double r;
	if (scanf("%d", &n) != 1 || ++n > N)
		return -1;
	//заполняем массив
	for (i = 0; i < n; i++)
		A[i] = i;
	//перебираем числа
	for (i = 2, r = sqrt(n); i <= r; i++)
		if (A[i]) //ищем простые
			for (j = i * i; j < n; j += i)
				A[j] = 0; //вычёркиваем
	for (i = 2; i < n; i++)
		if (A[i]) //делаем с нашими простыми числами всё, что душе угодно
			printf("%d ", A[i]);
	return 0;
}
