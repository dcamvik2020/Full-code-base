#include <iostream>
#include <sstream>

#include <chrono>
class Timer {
private:
  using clock_t = std::chrono::high_resolution_clock;
  using second_t = std::chrono::duration<double, std::ratio<1> >;

  std::chrono::time_point<clock_t> m_beg;

public:
  Timer() : m_beg(clock_t::now()) {}

  void reset() {
    m_beg = clock_t::now();
  }

  double elapsed() const {
    return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
  }
};



int main ()
{
  unsigned u = 0;
  std::stringstream ss;

  Timer t;  
  for ( ; u < 100000000; ++u);
  std::cout << "time of 10^9 increments = " << t.elapsed() << "\n";

  t.reset();
  for ( ; u > 0; --u) ss << u;
  std::cout << "time of 10^9 (ss << num) = " << t.elapsed() << "\n";

  return 0;
}
