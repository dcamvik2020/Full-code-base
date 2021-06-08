

///Adjacency lists: for each vertex we have her neighbours
///1: 2, 3, ...
///2: ...
///For directed and not directed graphs!! -> we need to remember about it

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct List{
    unsigned item;
    struct List *next;
} List;

typedef struct {
    unsigned index;
    unsigned dist; /// from the source
    char *name;
    List *Adj;
    unsigned time_in;
    unsigned time_out;
    unsigned SCC_index;
} V;

void First_Initialisation_Graph(V *G, unsigned N);

List *Add_to_Adj(V *G, unsigned i,unsigned v);

void Read_G_Adj(V *G, unsigned N);

void Print_Adj(V *G, unsigned i);

void Free_Graph(V **G, unsigned N);

///V *G = NULL is necessary before calling the function
void Get_Adj_Lists(V **G, unsigned N); 
