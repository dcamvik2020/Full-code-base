#include <stdio.h>
#include <stdlib.h>

///sum of arguments from console

int main(int argc, char **argv)
{
    int i = 1, sum = 0;
    for (; i < argc; i++)
    {
        sum += atoi(argv[i]);
    }
    //printf("%d\n", sum);
    return sum;
}
