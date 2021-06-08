#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// 1000 + '\0'
#define N 1001

#define IF(func)       \
    if (!(func))       \
        perror(#func); \
    else               \

int main ()
{
    int fd;
    char name[] = "aaa.fifo";
    umask(0);
    IF (mknod(name, 0666, 0) >= 0)
    {
        IF ((fd = open(name, O_WRONLY | O_APPEND)) >= 0)
        {
            ssize_t size;
            char buf[N] = "2 2";
            puts("2");
            
            IF ((size = write(fd, buf, strlen(buf) + 1)) >= 0) {
                puts("3");
            }

	    strcpy(buf, "23 45");
            IF ((size = write(fd, buf, strlen(buf) + 1)) >= 0) {
                puts("4");
            }

	    strcpy(buf, "12 34");
            IF ((size = write(fd, buf, strlen(buf) + 1)) >= 0) {
                puts("5");
            }

            close(fd);
        }
    }
    puts("exit");
    return 0;
}
