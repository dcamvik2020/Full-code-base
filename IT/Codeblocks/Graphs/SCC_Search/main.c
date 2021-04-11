#include "DFS.h"

int cmp(const void *a, const void *b) {
    return ((V*)b)->time_out - ((V*)a)->time_out;
}

void Modified_DFS_visit(V *G, short *was, unsigned *source)
{
    List *list;
    printf("%-4u", *source);
    for (list = G[*source].Adj; list->next; list = list->next)
    {
        *source = (unsigned) (list - G->Adj);
        DFS_visit(G, was, *source);
    }
    ++(*source);
}

void Modified_DFS(V *G, short *was, unsigned N, unsigned source)
{
    unsigned v = source;
    while (v != N)
    {
        Modified_DFS_visit(G, was, &v);
        puts("");
    }
}

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
    Modified_DFS(G, was, N, source);

    ///top sort
    qsort(G, N, sizeof(V), cmp);

    ///the second DFS, modified

    ///free memory
    Free_Graph(&G, N);
    free(was);
    return 0;
}
