#include "Adjacency_lists.h"

///Adjacency lists: for each vertex we have her neighbours
///1: 2, 3, ...
///2: ...
///For directed and not directed graphs!! -> we need to remember about it

void First_Initialisation_Graph(V * G, unsigned N) {
    unsigned i;
    for (i = 0; i < N; i++) {
        G[i].index = i;
        G[i].dist = UINT_MAX;
        G[i].name = NULL;
        G[i].Adj = NULL;
    }
}

List *Add_to_Adj(V * G, unsigned i,unsigned v) {
    List *new_item = (List*) malloc(sizeof(List));
    List *list;
    new_item->item = v;
    new_item->next = NULL;
    if (G[i].Adj) {
        for (list = G[i].Adj; list->next; list = list->next);
        list->next = new_item;
    } else {
        G[i].Adj = new_item;
    }
    return G[i].Adj;
}

void Read_G_Adj(V * G, unsigned N) {
    unsigned i, x;
    for (i = 0; i < N; i++) {
        printf("   %-7u    ", i);
        do {
            scanf("%u", &x);
	    /// "int" is always casted to "unsigned"
            /// without (x-N) -> ((int)x) - ((unsigned)N) -> very big number > 0
            if ((int) (x - N) >=  0)  {
                perror("\n\n\t\tThe index is not correct!\n\n");
                return;
            }
            G[i].Adj = Add_to_Adj(G, i, x);
        } while (x != (unsigned) -1);
    }
}

void Print_Adj(V * G, unsigned i) {
    List *list;
    for (list = G[i].Adj; list->next; list = list->next) {
        printf("%-4u", list->item);
    }
    if (!(list - G[i].Adj)) {
        printf("no neighbours");
    }
    puts("");
}

void Free_Graph(V ** G, unsigned N) {
    unsigned i;
    for (i = 0; i < N; i++) {
        free((*G)[i].name);
        
	List * waste;
	for ( ; (*G)[i].Adj; ) {
            waste = (*G)[i].Adj;
	    (*G)[i].Adj = (*G)[i].Adj -> next;
	    free(waste);
	}
    }
    free(*G);
}

///V *G = NULL is necessary before calling the function
void Get_Adj_Lists(V ** G, unsigned N)  {
    //unsigned i;
    *G = (V *) malloc(N * sizeof(V));
    First_Initialisation_Graph(*G, N);

    ///making adjacency lists
    printf("Vertex    ->  Neighbours\n");
    Read_G_Adj(*G, N);
/*
    ///print all lists
    printf("\n\nVertex    ->  Neighbours\n");
    for (i = 0; i < N; i++)
    {
        printf("   %-7u    ", i);
        Print_Adj(G, i);
    }
*/
}

/*
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
*/
