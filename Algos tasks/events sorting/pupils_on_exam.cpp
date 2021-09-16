/// Have : N pupils, M teachers 
/// Know : pupils [0, N), teacher looks at [b_i, e_i]
/// Need : # of students that can cheat (teachers don't see them)

#include <iostream>
#include <vector>
#include <algorithm>

int main ()
{
  int N, M;
  std::cin >> N >> M;
  std::vector<std::pair<int, int>> time_type(2 * M);
  for (int i = 0; i < 2 * M; i += 2)
  {
    int tin, tout;               /// idea : time segments <---> only 2 points
    std::cin >> tin >> tout;     /// are important (start, finish) ---> 2 types
    time_type[i]   = {tin, -1};  /// of time moments (1 = out, -1 = in) --> sort
    time_type[i+1] = {tout, 1};  /// by time, then sort by type --> in before out at
  }                              /// segment's borders --> [1,2] & [2,3] cover [1,3]

  std::sort(time_type.begin(), time_type.end());

  int counter = 0;
  int start, finish;
  int total_time = 0;
  for (int i = 0; i < 2 * M; ++i)
  {
    if (time_type[i].second == -1)
    {
      if (counter == 0)
        finish = start = time_type[i].first;
      counter++;
    }
    else if (time_type[i].second == 1)
    {
      counter --;
      if (counter == 0)
        finish = time_type[i].first + 1;
    }

    total_time += finish - start;
  }
  std::cout << N - total_time << "\n";
  return 0;
}
