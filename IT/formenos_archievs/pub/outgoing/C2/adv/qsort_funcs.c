#include <stdlib.h>

int g_a, g_b;

int cmp_func(const void *p1, const void *p2) {
	return (*(int (**)(int a, int b))p1)(g_a, g_b) - (*(int (**)(int a, int b))p2)(g_a, g_b);
}

void shake(/*int (**funcs)(int a, int b)*/ void *funcs, int n, int a, int b) {
	g_a = a; g_b = b;
	qsort(funcs, n, sizeof(/*int (*)(int a, int b)*/ void *), cmp_func);
}
