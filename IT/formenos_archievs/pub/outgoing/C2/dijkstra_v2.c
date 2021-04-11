#include <stdio.h>
#include <stdlib.h>

typedef struct List List;
typedef struct Graph Graph;

struct List {
	Graph *item;
	unsigned weight;
	List *next;
};

struct Graph {
	unsigned mark;
	unsigned visited;
	List *neighbors;
};

//always update head of list using returned link
List *list_add(List *list, Graph *item, unsigned weight) {
	List *new_item = (List *) malloc(sizeof(List));
	new_item->item = item;
	new_item->weight = weight;
	new_item->next = list;
	return new_item;
}

void list_destroy(List *list) {
	if (list) {
		list_destroy(list->next);
		free(list);
	}
}

unsigned get_next_node(Graph *G, unsigned n) {
	unsigned i, m = (unsigned)(-1);
	for (i = 0; i < n; i++)
		if (!G[i].visited && (m == (unsigned)(-1) || G[i].mark < G[m].mark))
			m = i;
	return m;
}

int main(void) {
	unsigned i, n, m, x, y, w;
	Graph *G;
	scanf("%u %u", &n, &m);
	//initialization
	G = (Graph *) calloc(n, sizeof(Graph));
	for (i = 0; i < n; i++)
		G[i].mark = (unsigned)(-1);
	//input
	for (i = 0; i < m; i++) {
		scanf("%u %u %u", &x, &y, &w);
		G[x].neighbors = list_add(G[x].neighbors, &G[y], w);
		G[y].neighbors = list_add(G[y].neighbors, &G[x], w);
	}
	//start
	scanf("%u", &x);
	G[x].mark = 0;
	while ((i = get_next_node(G, n)) != (unsigned)(-1)) {
		List *list;
		G[i].visited = 1;
		//process neighbors
		for (list = G[i].neighbors; list; list = list->next)
			if (!list->item->visited && G[i].mark + list->weight < list->item->mark)
				list->item->mark = G[i].mark + list->weight;
	}
	//output
	for (i = 0; i < n; i++)
		printf("%d ", (int)G[i].mark);
	printf("\n");
	//free
	for (i = 0; i < n; i++)
		list_destroy(G[i].neighbors);
	free(G);
	return 0;
}
