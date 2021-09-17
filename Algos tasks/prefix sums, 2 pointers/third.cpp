/// Have : mountain chain ---> N points in 2D
///        M routes (can be :   left->right   or   right->left)
///        1 <= N,M <= 30000, 1 ≤ xi,yi ≤ 30 000, 1 ≤ si,fi ≤ N
///        (si , fi can be <. > or =)
/// Know : each 2 vertexes have different x[i] (x_prev < x_next)
///        route (маршрут) ---> start, finish
///        y[i-1] < y[i] ---> raise (подъём) : y[i]-y[i-1]
/// Need : for every route find total sum for raises

#include <iostream>
#include <vector>

int main ()
{
  int N;
  std::cin >> N;
  std::vector<int> mountainX(N), mountainY(N);
  for (int i = 0; i < N; ++i)
    std::cin >> mountainX[i] >> mountainY[i];

  int M;
  std::cin >> M;
  int start, finish, totalraise, totaldown;
  for (int i = 0; i < M; ++i)
  {
    totalraise = 0;
    std::cin >> start >> finish;
    
    std::cout << totalraise;
  }
  return 0;
}
