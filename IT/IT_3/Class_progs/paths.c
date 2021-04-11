#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search_symb(char **t, char symb) {
    char *p = NULL;
    while (p = strchr(*t, symb)) {
        *p = 0;
        puts(*t);
        *t = p + 1;
    }
} 

int main(int argc, char *argv[], char *envp[]) {
    int i;
    char *s = NULL, *t = NULL;
    for (i = 0; envp[i] && strncasecmp(envp[i], "PATH=", 5); i++);
    if (envp[i]) {
        s = strdup(envp[i]+5);
        t = s;
        if(strchr(t, ';')) {
            search_symb(&t, ';');
        } else {
            search_symb(&t, ':');
        }
        puts(t);
        free(s);
    }
    return 0;
}

