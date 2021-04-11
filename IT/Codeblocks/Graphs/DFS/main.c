#include "DFS.h"

int main()
{
    unsigned N, source;
    short *was = NULL;
    V *G = NULL;

    ///input
    printf("Enter the number of vertexes: ");
    scanf("%u", &N);
    was = (short *) calloc(N, sizeof(short));
    printf("Enter the index of source: ");
    scanf("%u", &source);
    Get_Adj_Lists(&G, N);

    ///DFS
    DFS(G, was, N, source);

    ////print distances
    //Print_dist(G, N);

    ///free memory
    Free_Graph(&G, N);
    free(was);
    return 0;
}
