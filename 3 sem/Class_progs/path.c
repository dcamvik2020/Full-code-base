#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char *argv[], char *envp[]) {
    int i;
    for (i = 0; envp[i] && strncasecmp("PATH=", envp[i], 5); i++);
    if (envp[i])
        puts(envp[i]+5);
    return 0;
}

