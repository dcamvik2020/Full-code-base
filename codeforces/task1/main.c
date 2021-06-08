#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, x;
    char s[200001];
    scanf("%d\n%s\n%d", &n, s, &m);
    for (i = 0; i < m; i++)
    {
        int letters[26] = {0}, j = 0, counter = 0;
        char t[200001] = {0};
        scanf("%s", t);
        for (j = 0; t[j] || counter; j++)
        {
            if (j < strlen(t))
            {
                x = t[j] - 'a';
                letters[t[j] - 'a']++;
                counter++;
            }
            x = s[j] - 'a';
            if (letters[x])
            {
                letters[x]--;
                counter--;
            }
        }
        printf("%d\n", j);
    }
    return 0;
}
