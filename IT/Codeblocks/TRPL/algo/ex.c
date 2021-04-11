#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s = NULL, c = 'x';
    s = (char *) malloc(10 * sizeof(char));
    strcpy(s, "ada");
    printf("size = %d, len = %d\n", sizeof(s), strlen(s)); // 8, 3
    s = (char *) realloc(s, 20 * sizeof(char));
    printf("size = %d, len = %d\n", sizeof(s), strlen(s)); // 8, 3
    
    printf("size(c) = %d\n", sizeof(c)); // 1
    
    free(s);
    return 0;
}
