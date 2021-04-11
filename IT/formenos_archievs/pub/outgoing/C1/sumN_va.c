#include <stdarg.h>

int sumN(unsigned n, ...) {
	int s = 0;
	unsigned i;
	va_list v;
	va_start(v, n);
	for (i = 0; i < n; i++)
		s += va_arg(v, int);
	va_end(v);
	return s;
}
