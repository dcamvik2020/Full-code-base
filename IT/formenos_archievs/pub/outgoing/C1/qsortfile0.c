#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1025

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
			char (*text)[N];
			fscanf(input, "%i\n", &n);
			if ((text = (char (*)[N]) malloc(n * N)) != NULL) {
				for (i = 0; i < n; i++) {
					if (!fgets(text[i], N, input))
						text[i][0] = '\0';
					l = strlen(text[i]);
					if (l > 0 && text[i][l-1] == '\n')
						text[i][l-1] = '\0';
				}
				qsort(text, n, N, (int (*)(const void *, const void *))strcmp);
				for (i = 0; i < n; i++) {
					fputs(text[i], output);
					fputs("\n", output);
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
