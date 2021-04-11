#include <stdio.h>
#include <stdlib.h>

#define char_start 'à'
#define char_stop 'ß'

/*int check(const char *s)
{
    return cmp(s, "axax");
}*/

int perebor(char *s, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {

    }
}

int bruteforce(char *buf, int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < i; j++)
        {
            s[j] = char_start;
        }
        perebor(buf, i);
    }
}

int main()
{
    return 0;
}
