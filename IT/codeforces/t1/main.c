#include <stdio.h>
#include <stdlib.h>

void str_search(char *s, int i, int k, int n)
{
    int j = i, k0 = 0, k1 = 0;
    int n0 = 0, n1 = 0, i0 = i;
    for (; s[j]; j++)
    {
        if (s[j] == '1') k1++;
        else k0++;
    }
    if (!s[i] || (k0 != k1))
    {
        printf("%d\n", k);
        puts(s);
        return;
    }
    for (j = i; s[j]; j++)
    {
        if (s[j] == '1')
            n1++, k1--;
        else
            n0++, k1--;
        if (n0!=n1 && k0!=k1)
            i0 = j;
    }
    for (j = 2*n; j > i0 + 1; j--) s[j] = s[j-1];
    s[i0 + 1] = ' ';
    str_search(s, i0+2, k+1, n);
}

int main()
{
    int n, i = 0, k0 = 0, k1 = 0;
    char *s = NULL;
    scanf("%d", &n);
    s = (char*) calloc(2*n+1, sizeof(char));
    scanf("%s", s);
    str_search(s, 0, 1, n);
    free(s);
    return 0;
}
