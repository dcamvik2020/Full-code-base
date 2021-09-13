#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *input = NULL;
    char c;
    if (argc == 1)
    {
        printf("Usage:\n notepad <filename>");
        return 0;
    }
    input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("fopen: No such file or directory");
        fclose(input);
        return 0;
    }
    while (fscanf(input, "%c", &c) == 1)
    {
        fprintf(stdout, "%c", c);
    }
    fclose(input);
    return 0;
}
