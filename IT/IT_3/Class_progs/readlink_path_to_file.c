#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define PATH_MAX 4096

int main() {
    int n;
    char path[PATH_MAX + 1] = "", *p = NULL;
    if((n = readlink("/proc/self/exe" , path, PATH_MAX)) > 0) {
        path[n] = '\0';
        if ((p = strrchr(path, '/')) == path) {
            putc('/', stdout); // root
        }
        *p = '\n';
        puts(path);
    } else {
        perror("readlink");
    }
    return 0;
}
