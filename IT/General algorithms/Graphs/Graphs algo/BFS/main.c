#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\Sony\Desktop\IT\General algorithms\Graphs\Ways to store\Adjacency lists\Adj_Lists.c"
#include "C:\Users\Sony\Desktop\IT\General algorithms\Graphs\Graphs algo\BFS\queue.c"

void BFS(Queue **Q, V *G, short *was, int N)
{
    unsigned v, x;
    List *list;
    while (*Q)
    {
        v = Dequeue(Q);
        for (list = G[v].Adj; list->next; list = list->next)
        {
            x = list->item;
            if (!was[x])
            {
                G[x].dist = G[v].dist + 1;
                was[x] = 1;
                *Q = Enqueue(*Q, x);
            }
        }
    }
}

void Print_dist(V *G, unsigned N)
{
    unsigned i;
    puts("\nThe distance are:");
    for (i = 0; i < N; i++)
    {
        printf("dist(source, %u) = %u\n", i, G[i].dist);
    }
}

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
    BFS(&Q, G, was, N);

    ///print distances
    Print_dist(G, N);

    ///free memory
    Free_Graph(&G, N);
    free(was);
    return 0;
}
