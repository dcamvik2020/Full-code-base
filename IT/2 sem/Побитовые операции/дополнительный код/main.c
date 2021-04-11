#include <stdio.h>

int main()
{
    int c, i;
    scanf("%d", &c);
    for (i = 0; i < 8; i++)
    {
        putchar('0' + ((c >> (7 - i)) & 1));
    }
    return 0;
}
