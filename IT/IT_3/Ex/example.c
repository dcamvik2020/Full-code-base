#include <stdio.h>

int main() {
    int i, x;
    char s[100];
    fgets(s, 100, stdin);
    for (i = 0; i < 3; i++) { // scanf() doesn't 
	sscanf(s, "%d ", &x); //
        printf("%d", x);
    }
    return 0;
}
