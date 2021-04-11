#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define N 4096

int main(int argc, char *argv[]) {
    int input, output, res = 0;
    char buf[N];
    ssize_t size;
    if (argc < 3) {
        fprintf(stderr, /*"cp: too few arguments\n*/"Usage:\ncp <oldfile> <newfile>\n");
        return 1;
    }
    if ((input = open(argv[1], O_RDONLY)) != -1) {
        if ((output = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0777)) != -1) {
            while ((size = read(input, buf, N)) > 0) {
                if (write(output, buf, size) != size) {
                    sprintf(buf, "write(%s)", argv[2]);
                    perror(buf);
                }
            }
            if (size == -1) {
                sprintf(buf, "read(%s)", argv[1]);
                perror(buf);
            }
            close(output);
        } else {
            sprintf(buf, "open(%s)", argv[2]);
            perror(buf);
            res =  3;
        }
        close(input);
    } else {
        sprintf(buf, "open(%s)", argv[1]);
        perror(buf);
        res = 2;
    }
    return res;
}
