#include <stdio.h>
#include <stdlib.h>
#include "Adj_Lists.h"

extern unsigned TIME;

void DFS_visit(V *G, short *was, unsigned source);

void DFS(V *G, short *was, unsigned N, unsigned source);
