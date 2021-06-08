#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1025

int comp_func(const void *p1, const void *p2) {
	return strcmp(*(char **)p1, *(char **)p2);
}

int main(int argc, char *argv[]) {
	char input_file_name_buf[1024], output_file_name_buf[1024], *input_file_name, *output_file_name;
	FILE *input, *output;
	if (argc > 2) {
		input_file_name = argv[1];
		output_file_name = argv[2];
	} else {
		gets(input_file_name_buf);
		input_file_name = input_file_name_buf;
		gets(output_file_name_buf);
		output_file_name = output_file_name_buf;
	}
	if ((input = fopen(input_file_name, "rt")) != NULL) {
		if ((output = fopen(output_file_name, "wt")) != NULL) {
			int i, n, l;
			char buf[N], **text;
			fscanf(input, "%i\n", &n);
			if ((text = (char **) malloc(n * sizeof(char *))) != NULL) {
				for (i = 0; i < n; i++) {
					if (!fgets(buf, sizeof buf, input))
						buf[0] = '\0';
					l = strlen(buf);
					if (l > 0 && buf[l-1] == '\n')
						buf[l-1] = '\0';
					text[i] = strdup(buf);
				}
				qsort(text, n, sizeof(char *), comp_func);
				for (i = 0; i < n; i++) {
					fputs(text[i], output);
					fputs("\n", output);
					free(text[i]);
				}
				free(text);
			}
			fclose(output);
		} else
			perror("fopen(output.txt)");
		fclose(input);
	} else
		perror("fopen(input.txt)");
	return 0;
}
