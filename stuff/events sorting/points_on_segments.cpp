/// Have : N segments [a,b] and M points [x] on axis X \in \mathbb{Z}
/// Know : all numbers are integers, 1 <= n,m <= 10^5, abs([x]) <= 10^9
/// Need : for every [x] count # of segments that contain it


/// TODO          TODO           TODO          TODO

#include <iostream>
#include <vector>
#include <algorithm>

int main ()
{
  int N, M;
  std::cin >> N >> M;
  std::vector<std::pair<int, int>> point_type(2 * N + M);
  for (int i = 0; i < N; i++)
  {
    int start, finish;
    std::cin >> start >> finish;
    point_type[2 * i]     = {start, -1}; /// in sorted point_type
    point_type[2 * i + 1] = {finish, 1}; /// start should be earlier
  }
  
  for (int i = 0; i < M; ++i)
  {
  	int point;
    std::cin >> point;
    point_type[2 * N + i] = {point, 0};
  }
  
  /// then if we have at same point : [x], start of one segment
  /// and finish of another segment ---> than firstly we count +1
  /// segment, then we check # of segments, then we count -1
  std::sort(point_type.begin(), point_type.end());

  /// Note : all points we save in one array
  int counter = 0;
  for (int i = 0; i < 2 * N + M; ++i)
  {
    if (point_type[i].second == -1)
      counter++;
    else if (point_type[i].second == 0)
      std::cout << counter << " ";
    else if (point_type[i].second == 1)
      counter--;
  } 
  std::cout << "\n";
  return 0;
}
