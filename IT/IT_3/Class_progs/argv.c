#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i = 1;
    for (; i < argc; i++)
        puts(argv[i]);
    return 0;
}

