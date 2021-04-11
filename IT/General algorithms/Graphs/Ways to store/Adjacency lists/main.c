#include <stdio.h>
#include <stdlib.h>
#include "Adj_Lists.c"

///Adjacency lists: for each vertex we have her neighbours
///1: 2, 3, ...
///2: ...
///For directed and not directed graphs!! -> we need to remember about it

int main()
{
    ///input
    unsigned N;
    V *G = NULL;
    printf("Enter the number of vertexes: ");
    scanf("%u", &N);
    Get_Adj_Lists(&G, N);
    return 0;
}
