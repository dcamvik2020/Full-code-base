#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define N 4096

int main() {
    char path[N], *p;
    if (fgets(path, N, stdin)) {
        if ((p = strchr(path, '\n'))) {
            *p = 0;
        }
        if (chdir(path) < 0) {
            perror("chdir");
        }
    }
    if (!getcwd(path, N)) {
        perror("getcwd");
    } else {
        puts(path);
    }
    return 0;
}

