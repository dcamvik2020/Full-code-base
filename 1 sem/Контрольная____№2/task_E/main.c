#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s = (char) malloc(sizeof(char));
    int k = 0, i = 0;
    while (scanf("%c",s[i]))
    {
        if (s[i] < 'A' || s[i] > 'Z')
        {
            k++;
        }
        i++;
    }


    printf("%d\n", k);
    free(s);
    return 0;
}
