#include <stdio.h>

int symbol(char c)
{
    switch (c)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return 0;
}

int main()
{
    char s[16]; /// the longest number is MMMDCCCLXXXVIII
    int x, y, sum = 0, i;
    scanf("%s", s);
    for (i = 0; s[i]; i++)
    {
        x = symbol(s[i]);
        y = symbol(s[i + 1]);
        if (x < y)
        {
            sum -= x;
        }
        else
        {
            sum += x;
        }
    }
    printf("%d\n", sum);
    return 0;
}
