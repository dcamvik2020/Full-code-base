#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define nulls(c, i, len) ((i) >= (len) ? '0' : (c))

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

int main()
{
    char s1[1002], s2[1002], t;
    int len1, len2, max_len, rest = 0, i;
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
        s1[i] = nulls(s1[i], i, len1);
        s2[i] = nulls(s2[i], i, len2);
        t = s2[i] - '0' + s1[i] - '0' + rest;
        rest = t >> 1;
        s2[i] = (t & 1)+ '0';
    }
    for (; max_len > 0 && s2[max_len] == '0'; max_len--); ///if s2 contain only zeros
    s2[++max_len] = '\0';
    ///reverse
    reverse_array(s2, max_len);
    puts(s2);
    return 0;
}
