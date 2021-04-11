#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int age;
	double height;
	char name[20];
} Student;

int cmp_func1(const void *p1, const void *p2) {
	return ((const Student *)p1)->age - ((const Student *)p2)->age;
}

int cmp_func2(const void *p1, const void *p2) {
	double d = ((const Student *)p1)->height - ((const Student *)p2)->height;
	return d > 0 ? 1 : (d < 0 ? -1 : 0);
}

int cmp_func3(const void *p1, const void *p2) {
	return strcmp(((const Student *)p1)->name, ((const Student *)p2)->name);
}

int main(void) {
	Student studs[100];
	int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %lf %s", &studs[i].age, &studs[i].height, studs[i].name);

	qsort(studs, n, sizeof(Student), cmp_func);

	for (i = 0; i < n; i++)
		printf("%d %lg %s\n", studs[i].age, studs[i].height, studs[i].name);
	return 0;
}
