#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

void reverse_array(char *s, int len)
{
    int i;
    for (i = 0; i < len / 2; i++)
    {
        char t = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = t;
    }
}

int num(char c)
{
    if (c == '$')
        return -1;
    else
        return c-'0';
}


int main()
{
    char s1[1002], s2[1002], t, rest = '0';
    int len1, len2, max_len, i;
    scanf("%s", s1);
    scanf("%s", s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    max_len = max(len1, len2);
    ///reverse
    reverse_array(s1, len1);
    reverse_array(s2, len2);
    ///reverse sum
    for (i = 0; i <= max_len; i++)
    {
        if (i >= len1)
            s1[i] = '0';
        if (i >= len2)
            s2[i] = '0';
        t = num(s1[i]) + num(s2[i]) + num(rest);
        switch (t)
        {
            case -3:
                rest = '$';
                s2[i] = '0';
                break;
            case -2:
                rest = '$';
                s2[i] = '1';
                break;
            case -1:
                rest = '0';
                s2[i] = '$';
                break;
            case 0:
                rest = '0';
                s2[i] = '0';
                break;
            case 1:
                rest = '0';
                s2[i] = '1';
                break;
            case 2:
                rest = '1';
                s2[i] = '$';
                break;
            case 3:
                rest = '1';
                s2[i] = '0';
                break;
        }
    }
    for (; max_len > 0 && s2[max_len] == '0'; max_len--); ///if s2 contain only zeros
    s2[++max_len] = '\0';
    ///reverse
    reverse_array(s2, max_len);
    puts(s2);
    return 0;
}
