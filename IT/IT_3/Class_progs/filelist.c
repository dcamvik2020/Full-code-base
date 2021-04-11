#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

// oficial max len of any path in Linux
#define MAX_PATH_LEN 4096

#define IF(func)        \
    if (!(func)) {      \
        perror(#func);  \
    } else              \

void scan_dir(const char *s) {
    DIR *dir;
    IF ((dir = opendir(s))) {
        struct dirent *pEntry;
        char tmp_file_pwd[MAX_PATH_LEN];
        // print all files
        while ((pEntry = readdir(dir)))  {
            if (((pEntry -> d_type) & DT_DIR) == 0) {
                printf("%s/%s\n", strcmp(s, "/") ? s : "", pEntry -> d_name);
            }
        }

        // print all directories with their interior
        rewinddir(dir);
        while ((pEntry = readdir(dir)))  {
            if (    ((pEntry -> d_type) & DT_DIR) &&
	            strcmp(pEntry -> d_name, ".") &&
		    strcmp(pEntry -> d_name, "..")    ) {
                sprintf(tmp_file_pwd, "%s/%s", strcmp(s, "/") ? s : "" , pEntry -> d_name);
                puts(tmp_file_pwd);
                scan_dir(tmp_file_pwd);
            }
        }
        IF (!closedir(dir)) {
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        puts("Too few arguments!");
    } else {
        scan_dir(argv[1]);
    }
    return 0;
}
