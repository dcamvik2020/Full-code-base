#include <stdio.h>
#include <windows.h>

void werror(const char *s) {
	LPTSTR Buf;
	if (!FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_MAX_WIDTH_MASK,
					NULL, GetLastError(), MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), (LPTSTR) &Buf, 0, NULL)) return;
//	perror(s);
	fprintf(stderr, "%s: %s\n", s, Buf);
	LocalFree(Buf);
}

int main(void) {
	char s[1024];
	HMODULE hModule;
	printf("Enter dynamic library name: ");
	gets(s);
	if ((hModule = LoadLibrary(s)) != NULL) {
		int (*add)(int a, int b);
		int (*sub)(int a, int b);
		int (*mul)(int a, int b);
		int (*div)(int a, int b);
		int a, b;
		scanf("%d %d", &a, &b);

		add = (int (*)(int a, int b)) GetProcAddress(hModule, "add");
		if (add)
			printf("%d + %d = %d\n", a, b, add(a, b));
		else
			werror("GetProcAddress");
		sub = (int (*)(int a, int b)) GetProcAddress(hModule, "sub");
		if (sub)
			printf("%d - %d = %d\n", a, b, sub(a, b));
		else
			werror("GetProcAddress");
		mul = (int (*)(int a, int b)) GetProcAddress(hModule, "mul");
		if (mul)
			printf("%d * %d = %d\n", a, b, mul(a, b));
		else
			werror("GetProcAddress");
		div = (int (*)(int a, int b)) GetProcAddress(hModule, "div");
		if (div)
			printf("%d / %d = %d\n", a, b, div(a, b));
		else
			werror("GetProcAddress");
		FreeLibrary(hModule);
	} else
		werror("LoadLibrary");
	return 0;
}
