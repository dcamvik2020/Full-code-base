#include <stdio.h>

unsigned get_next_node(unsigned Marks[100], unsigned Visited[100], unsigned n) {
	unsigned i, m = (unsigned)(-1);
	for (i = 0; i < n; i++)
		if (!Visited[i] && (m == (unsigned)(-1) || Marks[i] < Marks[m]))
			m = i;
	return m;
}

int main(void) {
	unsigned i, j, n, m, G[100][100] = {{0}}, Marks[100], Visited[100] = {0}, x, y, w;
	scanf("%u %u", &n, &m);
	//initialization
	for (i = 0; i < n; i++)
		Marks[i] = (unsigned)(-1);
	//input
	for (i = 0; i < m; i++) {
		scanf("%u %u %u", &x, &y, &w);
		G[x][y] = G[y][x] = w;
	}
	//start
	scanf("%u", &x);
	Marks[x] = 0;
	while ((i = get_next_node(Marks, Visited, n)) != (unsigned)(-1)) {
		Visited[i] = 1;
		//process neighbors
		for (j = 0; j < n; j++)
			if (G[i][j] > 0 && !Visited[j] && Marks[i] + G[i][j] < Marks[j])
				Marks[j] = Marks[i] + G[i][j];
	}
	//output
	for (i = 0; i < n; i++)
		printf("%d ", (int)Marks[i]);
	printf("\n");
	return 0;
}
