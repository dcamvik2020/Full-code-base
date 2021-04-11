#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *input = NULL;
    int c;
    if (argc < 2)
    {
        fprintf(stderr, "Usage:\nnotepad <filename>\n");
        return 0;
    }
    input = fopen(argv[1], "rt");
    if (input == NULL)
    {
        perror("fopen");
        return 0;
    }
    while ((c = fgetc(input)) != EOF)
    {
        putchar(c);
    }
    fclose(input);
    return 0;
}
