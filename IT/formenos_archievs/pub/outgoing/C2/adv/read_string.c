#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//free returned memory, please!
char *read_string(FILE *file) {
	char *res = NULL, *tmp;
	int old_size = 0, new_size = 4;
	do {
		res = (char *) realloc(res, new_size);
		if (!fgets(res + old_size, new_size - old_size, file)) {
			res[old_size] = '\0';
			break;
		}
//		puts(res);
		old_size = new_size - 1;
		new_size *= 2;
	} while (!strchr(res, '\n'));
	new_size = strlen(res);
	if (new_size > 0 && res[new_size-1] == '\n')
		res[--new_size] = '\0';
	if (new_size > 0 && res[new_size-1] == '\r') //for "rb" mode
		res[--new_size] = '\0';
	//return res;
	tmp = strdup(res);
	free(res);
	return tmp;
}

#define readln() read_string(stdin)

int main(void) {
	FILE *input, *output;
	char *s;
	int flag = 0;
	if ((input = fopen("input.txt", "rt")) != NULL) {
		if ((output = fopen("output.txt", "wt")) != NULL) {
			while (!feof(input)) {
				s = read_string(input);
				if (flag)
					fputs("\n", output);
				flag = 1;
				fputs(s, output);
				free(s);
			}
			fclose(output);
		} else
			perror("fopen(output.txt)");
		fclose(input);
	} else
		perror("fopen(input.txt)");
	return 0;
}
