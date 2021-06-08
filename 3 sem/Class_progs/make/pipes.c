// Task: 
// - to exec a prog (argv[1] = name of it)
// - to exchange with it 2 strings
//
// parent prog gives child prod the descriptors of two pipes
// s1 -> reading by child prog, s2 -> for writing by it

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define N 101

char *itostr(int num) {
    int x, log; // log (num) by 10
    char *res = NULL;
    for (x = num, log = 0; x; x /= 10, log++);
    res = (char *) calloc(log + 1, sizeof(char));
    for (x = log - 1; x >= 0; x--) {
        res[x] = num % 10 + '0';
        num /= 10;
    }
    return res;
}

int main(int argc, char *argv[]) {
    int fd1[2], fd2[2]; // fd1: par-child, fd2: ch-par
    pid_t res;
    ssize_t size, len;
    char buf[N] = "", *s1 = NULL, *s2 = NULL, *p = NULL;
    if (argc < 2) {
        return 1;
    } else {
        if (pipe(fd1) < 0) {
            perror("pipe1");
        } else {
            if (pipe(fd2) < 0) {
                perror("pipe2");
                close(fd1[0]);
                close(fd1[1]);
            } else {
                res = fork();
                if (res == -1) {
                    perror("fork");
                    close(fd1[0]);
                    close(fd1[1]);
                    close(fd2[0]);
                    close(fd2[1]);
                } else if (res == 0) { // child process
                    close(fd1[1]);
                    close(fd2[0]);
                    s1 = itostr(fd1[0]); // for reading by argv[1]
                    s2 = itostr(fd2[1]); // for writing by argv[1]
                    execlp(argv[1], argv[1], s1, s2, NULL);
                    free(s1);
                    free(s2);
                    close(fd1[0]);
                    close(fd2[1]);
                    return 2;
                } else { // parent proc
                    close(fd1[0]);
                    close(fd2[1]);
                    if (fgets(buf, N, stdin)) {
                        if ((p = strchr(buf, '\n'))) {
                            *p = 0;
                        }
                        len = (size_t) strlen(buf);
                        if (len && ((size = write(fd1[1], buf, len)) != len)) {
                            perror("write");
                        }
                    } else {
                        //puts("Error in fgets()");
                    }
                    if ((size = read(fd2[0], buf, N - 1)) < 0) {
                        perror("read");
                    } else {
                        buf[size] = 0;
                        puts(buf);
                    }
                    close(fd1[1]);
                    close(fd2[0]);
                }
            }
        }
    }
    return 0;
}

