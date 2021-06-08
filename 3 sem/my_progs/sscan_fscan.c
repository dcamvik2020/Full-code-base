#include <stdio.h>

int main() {
    char s[100], t[100];
    fgets(s, 100, stdin);
    sscanf(s, "cd    %s", t); // if (s == "cd  sdf") --> t = "sdf" 
    puts(t);
    return 0;
}
