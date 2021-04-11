#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **read_file(FILE *fInput, int *num_lines) {
	char **Data = NULL;
	char buf[4096];
	int idx = 0, len;
	*num_lines = 0;
	while (fgets(buf, sizeof buf, fInput)) {
		len = strlen(buf);
		if (len > 0 && buf[len-1] == '\n')
			buf[--len] = '\0';
		if (len > 0 && buf[len-1] == '\r')
			buf[--len] = '\0';
		if (idx >= *num_lines) {
			if (*num_lines == 0)
				*num_lines = 2048;
			*num_lines *= 2;
			Data = (char **) realloc(Data, *num_lines * sizeof(char *));
		}
		Data[idx++] = strdup(buf);
	}
	*num_lines = idx;
	Data = (char **) realloc(Data, *num_lines * sizeof(char *));
	return Data;
}

int main(void) {
	FILE *f;
	char **A = NULL;
	int i, n;
	if ((f = fopen("input.txt", "rt")) != NULL) {
		A = read_file(f, &n);
		fclose(f);
	} else
		perror("fopen");
	for (i = 0; i < n; i++)
		free(A[i]);
	free(A);
	return 0;
}
