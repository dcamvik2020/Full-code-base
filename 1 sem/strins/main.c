#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///         int strins(char *t, unsigned int size, const char *s, unsigned int idx);
///         "s" into "t" at "idx", size = sizeof(t), including '\0' (not strlen + 1)
/// if (success) return 0;
/// if (s == NULL || t == NULL) return -1;
/// if (sizeof(t) is too small) return -2, "t" isn't modified;
/// if (idx > strlen(t)) return -3;

#include <stdio.h>
#include <math.h>

int strins(char *t, unsigned int size_of_t, const char *s, unsigned int idx)
{
    unsigned int len_s = strlen(s), len_t = strlen(t), i;

    ///checks
    if (!s || !t) {
        puts("(s == NULL || t == NULL)");
        return -1;
    }
    if (size_of_t < len_s + len_t + 1) {
        puts("(sizeof(t) is too small)");
        return -2;
    }
    if (idx >= len_t + 1) {
        puts("(idx > strlen(t))");
        return -3;
    }


    ///insertion
    for (i = len_s + len_t; i >= idx + len_s; i--)
    {
        t[i] = t[i - len_s];
        if (!i)
            break;
    }
    for (i = idx; s[i - idx]; i++)
    {
        t[i] = s[i - idx];
    }
    puts(t);
    return 0;
}

int main(void) {
    char t[50] = "String1\nString2";
    printf("%d\n", strins(t, 50, "String to insert\n", 8));
    return 0;
}

