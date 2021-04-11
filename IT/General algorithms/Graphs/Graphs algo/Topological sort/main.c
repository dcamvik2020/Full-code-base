#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\Sony\Desktop\IT\General algorithms\Graphs\Ways to store\Adjacency lists\Adj_Lists.c"

unsigned TIME = 0;

void DFS_visit(V *G, short *was, unsigned source)
{
    List *list;
    was[source] = 1;
    G[source].time_in = TIME;
    TIME++;
    for (list = G[source].Adj; list->next; list = list->next)
        if (!was[list->item])
            DFS_visit(G, was, list->item);
    G[source].time_out = TIME;
    TIME++;
}

void DFS(V *G, short *was, unsigned N, unsigned source)
{
    unsigned v;
    DFS_visit(G, was, source);
    for (v = 0; v < N; v++)
        if (!was[v])
            DFS_visit(G, was, v);
    puts("\nvertex        in          out");
    for (v = 0; v < N; v++)
        printf("%u           %u           %u\n", v, G[v].time_in, G[v].time_out);
}

int cmp(const void *a, const void *b) {
    return ((V*)b)->time_out - ((V*)a)->time_out;
}

int main()
{
    unsigned N, source, i;
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

    ///top sort
    qsort(G, N, sizeof(V), cmp);

    ///print sorted graph
    for(i = 0; i < N; i++)
        printf("%-4u", G[i].index);

    ///free memory
    Free_Graph(&G, N);
    free(was);
    return 0;
}
