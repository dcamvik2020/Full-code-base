#include <iostream>
#include <ctime>
#include <iomanip>

class Timer {
public :
  Timer() : workTime(clock()) {};
  ~Timer() {
    workTime = clock() - workTime;
    workTime = (double) workTime / CLOCKS_PER_SEC;
    std::cout << "Time of program's work = ";
    /// << std::fixed << std::setprecision(15) << workTime << "\n";
    printf("%lf\n", workTime);
  }
private :
  double workTime;
};

void Usage () {
  std::cout
    << "Usage :\n"
    << "\t./main N mod proc\n"
    << "\tN = matrix size\n"
    << "\tmod = max element value + 1.\n"
    << "\tproc = number of processes";
}

