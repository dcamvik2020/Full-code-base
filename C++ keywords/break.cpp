#include <iostream>

int main () {
  if (1) {
    break;  /// ERROR : it's OK only in loops, switches
  }
  return 0;
}
