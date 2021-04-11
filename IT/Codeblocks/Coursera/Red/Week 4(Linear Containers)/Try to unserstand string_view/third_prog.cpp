#include <iostream>
#include <string_view>

using namespace std;

#include "../profile.h"
int main() {
  {
    LOG_DURATION("string");
    for (size_t i = 0; i < 10000000; ++i) {
      string s("abcdefgh");
    }
  }

  {
    LOG_DURATION("string_view");
    for (size_t i = 0; i < 10000000; ++i) {
      string_view s("abcdefgh");
    }
  }
  return 0;
}

// string: 1366 ms
// string_view: 26 ms

