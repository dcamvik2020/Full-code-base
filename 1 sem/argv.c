#include <stdio.h>
#include <stdlib.h>

///print all arguments of cmd-call... except it's name

int main(int argc, char **argv)
{
    int i = 1;
    for (; i < argc; i++)
        puts(argv[i]);
    return 0;
}
