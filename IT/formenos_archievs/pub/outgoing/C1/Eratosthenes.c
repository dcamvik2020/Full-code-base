#include <stdio.h>
#include <math.h>

#define N 100

int main(void)
{
	int i, j, n, A[N];
	double r;
	if (scanf("%d", &n) != 1 || ++n > N)
		return -1;
	//��������� ������
	for (i = 0; i < n; i++)
		A[i] = i;
	//���������� �����
	for (i = 2, r = sqrt(n); i <= r; i++)
		if (A[i]) //���� �������
			for (j = i * i; j < n; j += i)
				A[j] = 0; //�����������
	for (i = 2; i < n; i++)
		if (A[i]) //������ � ������ �������� ������� ��, ��� ���� ������
			printf("%d ", A[i]);
	return 0;
}
