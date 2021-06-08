#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define N 24
// 2 *(10+1) bytes for SIGNED a, b, '\0' and ' '

int main() {
    int fd[2], a, b;
    pid_t res;
    ssize_t size, len;
    char buf[N];
    if (pipe(fd) < 0) {
        perror("pipe");
    } else {
        res = fork();
        if (res == -1) {
            perror("fork");
            close(fd[0]);
            close(fd[1]);
        } else if (res == 0) { // child process
            close(fd[1]);
            return fd[0];
        } else { // parent proc
            close(fd[0]);
            scanf("%d %d", &a, &b);
            sprintf(buf, "%d %d", a + b, b * 2);
            len = (size_t) strlen(buf);
            if ((size = write(fd[1], buf, len)) != len) {
                perror("write");
            }
            close(fd[1]);
        }
    }
    return 0;
}

