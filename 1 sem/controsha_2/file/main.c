#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input, *output;
    int a, b;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    fscanf(input, "%d\n", &a);
    fscanf(input, "%d", &b);
    fprintf(output, "%d", a - b);
    fclose(input);
    fclose(output);
    return 0;
}
