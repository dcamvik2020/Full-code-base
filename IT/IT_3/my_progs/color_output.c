#include <stdio.h>

#define GREEN "\033[0;32m"
#define BOLD_GREEN "\033[1;32m"
#define BOLD_BLUE "\033[1;34m"
#define RESET "\033[0m"

int main() {
    printf(GREEN);
    puts("Hellow, world!");
    printf(BOLD_GREEN);
    puts("Hellow, world!");
    printf(BOLD_BLUE);
    puts("Hellow, world!");
    printf(RESET);
    puts("Hellow, world!");


    printf("%s===3%s sdfs\n", BOLD_GREEN,    RESET);
    return 0;
}
