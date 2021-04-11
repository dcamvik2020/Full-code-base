#include <stdio.h>

int main(void) {
    FILE *input, *output;
    if ((input = fopen("input.txt", "r")) != NULL) {
        if ((output = fopen("output.txt", "w")) != NULL) {
            //code itself
            int a, b;
            fscanf(input, "%d %d", &a, &b);
            fprintf(output, "%d\n", a + b);
            fclose(output);
        } else
            perror("fopen(output.txt)");
        fclose(input);
    } else
        perror("fopen(input.txt)");
    return 0;
}
