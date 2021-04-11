#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        puts("Too few arguments");
    } else {
        struct stat buf;
        if (stat(argv[1], &buf)) {
            perror("stat");
	} else {
            char type;
	    switch(buf.st_mode & 0170000) {
		case S_IFSOCK :
		    type = 's';
		    break;
		case S_IFLNK :
		    type = 'l';
                    break;
                case S_IFREG :
		    type = '-';
		    break;
		case S_IFBLK :
		    type = 'b';
                    break; 
                case S_IFDIR :
		    type = 'd';
		    break;
		case S_IFCHR :
		    type = 'c';
                    break; 
		case S_IFIFO :
		    type = 'f';
		    break;
	    }
            printf("rights: %o\n"
		   "file type: %c\n", 
		   buf.st_mode & 0777,
		   type);
	}
    }
    return 0; 
}
