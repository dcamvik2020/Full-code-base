#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 33
// 10 {tabs, \n, ' '}, 2 *(10+1) bytes for SIGNED a, b;
// we read a string --> '\0', but also it can contain '\n, but it's possible that there isn't '\n', --> read 32+1=33
// and check the last symbol

int main() {
    int fd[2], a, b;
    ssize_t size;
    pid_t res;
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
            close(fd[0]);
            return fd[1];
        } else { // parent proc
            close(fd[1]);
            if ((size = read(fd[0], buf, N - 1)) < 0) {
                // N-1=32 because there isn't '\n' and '\0' in pipe
                perror("read");
            } else {
                buf[size] = 0; // if it was '\n' --> it becomes '\0'
                sscanf(buf, "%d %d", &a, &b);
                printf("%d\n", a+b);
            }
            close(fd[0]);
        }
    }
    return 0;
}

