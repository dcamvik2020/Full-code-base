#include <stdio.h>

int main(int argc, char *argv[]) {
    char buf[10];
    FILE *input;
    if (argc != 2) {
        fprintf(stderr, "Usage:\n\"%s\" <filename>\n", argv[0]);
        fgets(buf, sizeof buf, stdin);
        return 0;
    }
    if ((input = fopen(argv[1], "rt")) != NULL) {
        while (fgets(buf, sizeof buf, input))
            fputs(buf, stdout);
        fclose(input);
    } else
        perror("fopen");
    fgets(buf, sizeof buf, stdin);
    return 0;
}
