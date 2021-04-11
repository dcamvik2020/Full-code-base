#include <stdio.h>

int main()
{
    static char s[1000001], res[4000001], x = 0;
    int i, j;
    scanf("%s", s);
    for(i = 0, j = 0; s[i]; i++, j += 4)
    {
        if ('A' <= s[i] && s[i] <= 'F')
        {
            x = s[i] - 'A' + 10;
        }
        else
        {
            x = s[i] - '0';
        }
        res[j] = ((x >> 3) & 1) + '0';
        res[j + 1] = ((x >> 2) & 1) + '0';
        res[j + 2] = ((x >> 1) & 1) + '0';
        res[j + 3] = (x & 1) + '0';
    }
    res[j] = '\0';
    for (j = 0; res[j] == '0' && res[j + 1]; j++);
    puts(res + j);
    return 0;
}
