#include <stdio.h>
#include <stdlib.h>

/// my_strstr <-> strstr from standard library in C, so it returns
/// pointer of sub-string(strstr) in the string(str) or ... NULL
/// my_strstr doesn't compare '\0'; if strlen(substr) == 0 -> return str;
/// we don't need to check rightness of arguments

char *my_strstr(const char *str, const char *substr)
{
    int i = 0, sublen = 0;
    char *q = (char*) substr, *p = (char*) str;
    while (substr[sublen])
        sublen++;
    if (!sublen)
        return (char*) str;
    for (; *p; p++)
    {
        while (*q && *(p + i) == *q) /// if (!(*q) || !(*(p+i))) -> fail
            q++, i++;
        if (i == sublen)
            return p;
        q = (char*) substr;        /// here i < sublen -> fail
        ///p += i > 0 ? i - 1 : 0; /// in some cases we can jump over a lot of times copied letters (str = qwertyaaaabcsd, substr = aaab)
        i = 0;                     /// so, it will be better to NOT! NOT! NOT! try ANY optimisations
    }
    return NULL;
}

int main()
{
    char *str = "a16342b345", *substr = "b3", *p = NULL;
    p = my_strstr(str, substr);
    if (p)
    {
        printf("first element of substr at %d place\n", p - str);
        puts(str);
        puts(p);
    }
    else puts("The sub-string wasn't found.");
    return 0;
}
