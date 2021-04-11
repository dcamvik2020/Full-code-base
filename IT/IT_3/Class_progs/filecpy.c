#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define N 4096

int main() {
    int input, output;
    char buf[N] = "";
    ssize_t size;
    if ((input = open("input.dat", O_RDONLY)) != -1) {
        if ((output = open("output.dat", O_CREAT | O_WRONLY | O_TRUNC, 0644)) != -1) {
            while ((size = read(input, buf, N)) > 0) {
                //printf("size = %d ", (unsigned int) size); puts(buf);
                if (write(output, buf, size) == -1) {
                    perror("write");
                }
            }
            if (size == -1) {
                perror("read");
            }
            close(output);
        } else {
            perror("fopen(output)");
        }
        close(input);
    } else {
        perror("fopen(input)");
    }
    return 0;
}
