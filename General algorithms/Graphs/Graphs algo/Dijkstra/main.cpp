#include <iostream>
#include <vector>
#include <climits>

#define DEBUG

void dijkstra (unsigned N, unsigned start, 
               std::vector<std::vector<int>> & edges, 
               std::vector<int> & dist) {
  unsigned cnt_visited = 0;
  std::vector<bool> visited(N, false);
  
  while (cnt_visited < N) {
#ifdef DEBUG    
	std::cout << "\n\nstart : " << start << "\n";
	std::cout << "visited : ";
	for (unsigned i = 0; i < N; ++i)
	  if (visited[i]) std::cout << i << " ";
    std::cout << "\n";
#endif

	for (unsigned j = 0; j < N; ++j) {
 
      if (visited[j] || start == j || edges[start][j] == 0)
        continue;
      
	  if (dist[start] + edges[start][j] < dist[j])
        dist[j] = dist[start] + edges[start][j];
      
	  /*
	  if (unvisited_with_min_label == N ||
	      dist[j] < dist[unvisited_with_min_label])
        unvisited_with_min_label = j;
	  */
    }
    
    visited[start] = true;
	cnt_visited++;
	unsigned unvisited_with_min_label = N;
	for (unsigned j = 0; j < N; ++j) {
	  if (visited[j])
	    continue;
      if (unvisited_with_min_label == N ||
	      dist[unvisited_with_min_label] > dist[j])
	    unvisited_with_min_label = j;
    }
	start = unvisited_with_min_label;

#ifdef DEBUG
    std::cout << "dist : ";
    for (unsigned i = 0; i < N; ++i)
      std::cout << dist[i] << " ";
    std::cout << "\n";
#endif
  }
}

int main () {
  /// get directed graph
  unsigned N;  /// vertexes
  std::cin >> N;
  std::vector<std::vector<int>> edges(N, std::vector<int>(N));
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < N; ++j) {
      std::cin >> edges[i][j]; // no cycles with < 0 edges sum
	}
  }
  
  /// get start point
  unsigned start;
  std::cin >> start;
  if (start >= N) {
    std::cout << "Wrong start vertex!\n";
	return 0;
  }
  
  /// get distances to other vertexes
  std::vector<int> dist(N, INT_MAX);
  dist[start] = 0;
  /*
  std::cout << "\n\nReceived data:\n";
  std::cout << "N = " << N << "\n";
  std::cout << "start = " << start << "\n";
  std::cout << "dist : ";
  for (unsigned i = 0; i < N; ++i)
    std::cout << dist[i] << " ";
  std::cout << "\n";
  */
  dijkstra(N, start, edges, dist);

  /// print distances
  for (unsigned i = 0; i < N; ++i)
    std::cout << dist[i] << " ";
  std::cout << "\n";

  return 0;
}
