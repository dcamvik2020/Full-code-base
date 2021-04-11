#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
	DIR *pDir;
	struct dirent *pEntry;
//	char buf[PATH_MAX];

	if (argc < 2) {
		fprintf(stderr, "Give me argument, plz!\n");
		return -1;
	}

	if ((pDir = opendir(argv[1])) != NULL) {
		while ((pEntry = readdir(pDir)) != NULL) {
			if ((pEntry->d_type & DT_DIR) == DT_DIR)
				printf("dir:  ");
			else
				printf("file: ");
			puts(pEntry->d_name);
		}
		closedir(pDir);
	} else
		perror("opendir");
	return 0;
}
