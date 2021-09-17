#include "BFS.h"

int main()
{
    unsigned N, source;
    short *was = NULL;
    V *G = NULL;
    Queue *Q = NULL;

    ///input
    printf("Enter the number of vertexes: ");
    scanf("%u", &N);
    was = (short *) calloc(N, sizeof(short));
    printf("Enter the index of source: ");
    scanf("%u", &source);
    Get_Adj_Lists(&G, N);
    G[source].dist = 0;
    was[source] = 1;
    Q = Enqueue(Q, source);

    ///BFS
    BFS(&Q, G, was);

    ///print distances
    Print_dist(G, N);

    ///free memory
    Free_Graph(&G, N);
    free(was);
    return 0;
}
