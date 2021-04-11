#include "BFS.h"

void BFS(Queue **Q, V *G, short *was) {
    unsigned v, x;
    List *list;
    while (*Q) {
        v = Dequeue(Q);
        for (list = G[v].Adj; list->next; list = list->next) {
            x = list->item;
            if (!was[x]) {
                G[x].dist = G[v].dist + 1;
                was[x] = 1;
                *Q = Enqueue(*Q, x);
            }
        }
    }
}

void Print_dist(V *G, unsigned N) {
    unsigned i;
    puts("\nThe distances are:");
    for (i = 0; i < N; i++) {
        printf("dist(source, %u) = %u\n", i, G[i].dist);
    }
}
