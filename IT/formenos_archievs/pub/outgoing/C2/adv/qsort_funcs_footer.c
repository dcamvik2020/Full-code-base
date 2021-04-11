
#include <stdio.h>
#include <stdlib.h>

void shake(/*int (**funcs)(int a, int b)*/ void *funcs, int n, int a, int b);

int A0(int a, int b) {
	return a + b;
}

int A1(int a, int b) {
	return a - b;
}

int A2(int a, int b) {
	return a * b;
}

int A3(int a, int b) {
	return a / b;
}

int A4(int a, int b) {
	return a % b;
}

int A5(int a, int b) {
	int res = 1;
	if (b < 0) {
		if (a == 1 || a == -1)
			return a;
		return 0;
	}
	for ( ; b > 0; b--)
		res *= a;
	return res;
}

int main(void) {
	typedef struct {
		int (*func)(int a, int b);
		char op;
	} OPS;
	OPS ops[] = {{A0, '+'}, {A1, '-'}, {A2, '*'}, {A3, '/'}, {A4, '%'}, {A5, '^'}};
#define N ((int)(sizeof ops / sizeof ops[0]))
	int (**A)(int a, int b);
	int i, j, n, a, b;
	scanf("%d %d %d", &a, &b, &n);
	A = (int (**)(int a, int b)) malloc(n * sizeof(void *));
	for (i = 0; i < n; i++)
		A[i] = ops[i%N].func;
/*	for (i = 0; i < n; i++) {
		for (j = 0; j < N && ops[j].func != A[i]; j++);
		fprintf(stderr, "%d %c %d = %d\n", a, ops[j].op, b, A[i](a, b));
	}*/
	shake(A, n, a, b);
	for (i = 0; i < n; i++) {
		//char get_func_oper(int (*func)(int a, int b))
		for (j = 0; j < N && ops[j].func != A[i]; j++);
		printf("%d %c %d = %d\n", a, ops[j].op, b, A[i](a, b));
	}
	free(A);
	return 0;
}
