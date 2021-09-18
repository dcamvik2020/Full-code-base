#include "DFS.h"

unsigned TIME = 0;

void DFS_visit(V *G, short *was, unsigned source) {
    List *list;
    was[source] = 1;
    G[source].time_in = TIME;
    TIME++;
    for (list = G[source].Adj; list->next; list = list->next) {
        if (!was[list->item]) {
            DFS_visit(G, was, list->item);
	}
    }
    G[source].time_out = TIME;
    TIME++;
}

void DFS(V *G, short *was, unsigned N, unsigned source) {
    unsigned v;
    DFS_visit(G, was, source);
    for (v = 0; v < N; v++) {
        if (!was[v]) {
            DFS_visit(G, was, v);
	}
    }
    puts("\nvertex        in          out");
    for (v = 0; v < N; v++) {
        printf("%u           %u           %u\n", v, G[v].time_in, G[v].time_out);
    }
}

