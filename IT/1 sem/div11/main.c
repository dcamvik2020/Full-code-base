#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[1001];
    int sum = 0, i;
    scanf("%s", s);
    for (i = 0; s[i]; i++)
    {
        if(i % 2 == 0)
            sum += s[i] - '0';
        else
            sum += '0' - s[i];
    }
    if (sum % 11 == 0)
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
    return 0;
}
