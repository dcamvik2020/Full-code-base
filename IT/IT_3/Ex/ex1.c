#include <stdio.h>

int main() {
    char s[100];
    FILE *file = fopen("aaa.fifo", "r");
    while (fgets(s, 100, file))
        puts(s);
    return 0;
}
