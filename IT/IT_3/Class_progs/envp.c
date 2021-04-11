#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    int i = 0;
    for (; envp[i]; i++)
        puts(envp[i]);
    return 0;
}

