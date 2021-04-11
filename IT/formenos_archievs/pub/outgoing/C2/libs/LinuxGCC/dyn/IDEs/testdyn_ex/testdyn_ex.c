#include <stdio.h>
#include <dlfcn.h>

int main(void) {
	char s[1024];
	void *handle;
	printf("Enter shared library name: ");
	gets(s);
	if ((handle = dlopen(s, RTLD_LAZY)) != NULL) {
		int (*add)(int a, int b);
		int (*sub)(int a, int b);
		int (*mul)(int a, int b);
		int (*div)(int a, int b);
		int a, b;
		scanf("%d %d", &a, &b);

		add = (int (*)(int a, int b)) dlsym(handle, "add");
		if (add)
			printf("%d + %d = %d\n", a, b, add(a, b));
		else
			fprintf(stderr, "dlsym: %s\n", dlerror());
		sub = (int (*)(int a, int b)) dlsym(handle, "sub");
		if (sub)
			printf("%d - %d = %d\n", a, b, sub(a, b));
		else
			fprintf(stderr, "dlsym: %s\n", dlerror());
		mul = (int (*)(int a, int b)) dlsym(handle, "mul");
		if (mul)
			printf("%d * %d = %d\n", a, b, mul(a, b));
		else
			fprintf(stderr, "dlsym: %s\n", dlerror());
		div = (int (*)(int a, int b)) dlsym(handle, "div");
		if (div)
			printf("%d / %d = %d\n", a, b, div(a, b));
		else
			fprintf(stderr, "dlsym: %s\n", dlerror());
		dlclose(handle);
	} else
		fprintf(stderr, "dlopen: %s\n", dlerror());
	return 0;
}
