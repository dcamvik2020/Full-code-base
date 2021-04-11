#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define N 3
#define IF(func)       \
    if (!(func))       \
        perror(#func); \
    else               \

int main(int argc, char *argv[]) {
    int file1, file2;
    if (argc < 2) {
        puts("Too few arguments");
    } else {
        IF ((file1 = open(argv[1], O_RDONLY)) >= 0) {  
	    IF ((file2 = open(argv[1], O_WRONLY | O_APPEND)) >= 0) {
	        char buf[N];
		ssize_t size;
		while ((size = read(file1, buf, N - 1)) >= 0) {
                    buf[size] = '\0';
                    write(file2, buf, size);  
                    printf("%s", buf);		    
		}
	        close(file2); 
	    }     
	    close(file1);
	}
    }
    return 0;
}
