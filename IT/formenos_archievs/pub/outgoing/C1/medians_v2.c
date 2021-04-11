#include <stdio.h>

int main(void)
{
	int x1, y1, x2, y2, x3, y3;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	printf("%lg %lg\n", (x1 + x2 + x3) / 3.0, (double)(y1 + y2 + y3) / 3);
	return 0;
}
