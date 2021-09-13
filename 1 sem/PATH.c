#include <stdio.h>
#include <string.h>

int main(int argc, char **argv, char **envp)
{
    int i = 0;
    for (; envp[i]; i++)
    {
        if (!strncasecmp(envp[i], "PATH=", 5))
        {
            puts(envp[i] + 5);
        }
    }
    return 0;
}
