#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <inttypes.h>

#define N 101

int strtoi(const char *s) {
    int num = 0, k = 1, i;
    for (i = strlen(s) - 1; i >= 0; i--) {
        num += (s[i] - '0') * k;
        k *= 10;
    }
    return num;
}

int main(int argc, char *argv[]) {
    int fd1, fd2; // fd1 -> reading, fd2 -> writing
    ssize_t size, len;
    char buf[N] = "", send[N]  = "Otsosi, potom prosi";
    
    if (argc < 3) {
        puts("too few params");
    } else {
        fd1 = strtoi(argv[1]);
        fd2 = strtoi(argv[2]);

        if ((size = read(fd1, buf, N - 1)) < 0) {
            perror("read");
        } else {
            buf[size] = 0;
            printf("str was received by child: %s\n", buf);
        }

        printf("str was send by child: %s\n", send);
	len = (size_t) strlen(send);
        if (len && ((size = write(fd2, send, len)) != len)) {
            perror("write");
        }
        
        close(fd1);
        close(fd2);
    }
    return 0;
}

