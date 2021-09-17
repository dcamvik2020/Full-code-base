#include <iostream>
#include "../profile.h"

using namespace std;

int main() {


  {
    LOG_DURATION("str.size(), += str.size()");
    string str(30, '\0');
    size_t tmp = 0;
    for (size_t it = 0; it < 10'000'000; ++it) {
      tmp += str.size();
    }
  }



  {
    LOG_DURATION("size_t size, += size");
    string str(30, '\0');
    size_t size = str.size();
    size_t tmp = 0;
    for (size_t it = 0; it < 10'000'000; ++it) {
      tmp += size;
    }
  }

  return 0;
}
