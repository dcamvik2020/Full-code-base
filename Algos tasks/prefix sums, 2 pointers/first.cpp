/// Have : N t-shirts, M trousers, colors are int from 1 to 10^7
///        in these vectors colors increase (sorted)
///        N, M from 1 to 10^7
/// Know : good outfit <----> min subtraction in colors
/// Need : the best outfit (color of t-shirt , color of trousers)

#include <iostream>
#include <vector>
#include <climits>

int main ()
{
  int N;
  std::cin >> N;
  std::vector<int> alltshirts(N); /// colors
  for (int i = 0; i < N; ++i)
  {
    std::cin >> alltshirts[i];
    //std::cout << alltshirts[i] << " ";
  }
  //std::cout << "\n";

  int M;
  std::cin >> M;
  std::vector<int> alltrousers(M); /// colors
  for (int j = 0; j < M; ++j)
  {
    std::cin >> alltrousers[j];
    //std::cout << alltrousers[j] << " ";
  }
  //std::cout << "\n";

  int i, j;
  int tshirt = 0, trousers = 0; /// for best norm
  int min_norm = INT_MAX; /// norm <--> goodness (linear algebra)
  for (i = 0, j = 0; i < N && j < M; )
  {
    int norm = std::abs(alltshirts[i] - alltrousers[j]);
    if (norm < min_norm)
    {
      min_norm = norm;
      tshirt = i;
      trousers = j;
    }
    if (alltshirts[i] == alltrousers[j]) break;
    if (alltshirts[i] <  alltrousers[j]) ++i;
    else ++j;
    
  }
  //std::cout << tshirt << " " << trousers << "\n";
  std::cout << alltshirts[tshirt] << " " << alltrousers[trousers] << "\n";
  return 0;
}
