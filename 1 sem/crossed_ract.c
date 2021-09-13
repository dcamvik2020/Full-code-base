#include <stdio.h>

//пересекаютс ли прямоугольники
int main()
{
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
    if (x3 >= x2 || y3 >= y2 || y4 <= y1 || x4 <= x1)
    {
        puts("NO");
    }
    else
    {
        puts("YES");
    }
    return 0;
}
