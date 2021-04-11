#include <stdio.h>
#include <string.h>
#include <io.h>

int main(int argc, char *argv[]) {
	long pDir;
	struct _finddata_t pEntry;
	char buf[FILENAME_MAX];

	if (argc < 2) {
		fprintf(stderr, "Give me argument, plz!\n");
		return -1;
	}

	strcpy(buf, argv[1]); strcat(buf, "\\*");
	if ((pDir = _findfirst(buf, &pEntry)) != -1) {
		do {
			if ((pEntry.attrib & _A_SUBDIR) == _A_SUBDIR)
				printf("dir:  ");
			else
				printf("file: ");
			puts(pEntry.name);
		} while (_findnext(pDir, &pEntry) != -1);
		_findclose(pDir);
	}
	return 0;
}
