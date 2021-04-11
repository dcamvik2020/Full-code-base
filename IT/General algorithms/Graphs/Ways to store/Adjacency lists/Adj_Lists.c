#include <limits.h>

typedef struct List{
    unsigned item;
    struct List *next;
} List;

typedef struct {
    unsigned index;
    unsigned dist;
    char *name;
    List *Adj;
    unsigned time_in;
    unsigned time_out;
    unsigned SCC_index;
} V;

void First_Initialisation_Graph(V *G, unsigned N)
{
    unsigned i;
    for (i = 0; i < N; i++)
    {
        G[i].index = i;
        G[i].dist = UINT_MAX;
        G[i].name = NULL;
        G[i].Adj = NULL;
    }
}

List *Add_to_Adj(V *G, unsigned i,unsigned v)
{
    List *new_item = (List*) malloc(sizeof(List));
    List *list;
    new_item->item = v;
    new_item->next = NULL;
    if (G[i].Adj)
    {
        for (list = G[i].Adj; list->next; list = list->next);
        list->next = new_item;
    } else {
        G[i].Adj = new_item;
    }
    return G[i].Adj;
}

void Read_G_Adj(V *G, unsigned N)
{
    unsigned i, x;
    for (i = 0; i < N; i++)
    {
        printf("   %-7u    ", i);
        do {
            scanf("%u", &x);
            if ((int) (x - N) >=  0) ///without (x-N) -> ((int)x) - ((unsigned)N) -> very big number > 0
            {
                perror("\n\n\t\tThe index is not correct!\n\n");
                return;
            }
            G[i].Adj = Add_to_Adj(G, i, x);
        } while (x != (unsigned) -1);
    }
}

void Print_Adj(V *G, unsigned i)
{
    List *list;
    for (list = G[i].Adj; list->next; list = list->next)
        printf("%-4u", list->item);
    if (!(list - G[i].Adj))
        printf("no neighbours");
    puts("");
}

void Free_Graph(V **G, unsigned N)
{
    unsigned i;
    for (i = 0; i < N; i++)
    {
        free((*G)[i].name);
        free((*G)[i].Adj);
    }
    free(*G);
}

void Get_Adj_Lists(V **G, unsigned N) ///V *G = NULL is necessary before calling the function
{
    //unsigned i;
    *G = (V*) malloc(N*sizeof(V));
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
