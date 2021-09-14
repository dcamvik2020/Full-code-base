#include <stdio.h>

int main()
{
    char s[12];
    int sum = 0, i;
    scanf("%s", s);
    for (i = 0; s[i]; i++)
    {
        sum = sum * 3 + s[i] - '0';
    }
    printf("%d\n", sum);
    return 0;
}
