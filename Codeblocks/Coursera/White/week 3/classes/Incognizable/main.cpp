#include <iostream>
#include <vector>

using namespace std;

/// task : to create a type
/// that will work with main-cmd

/// it can be just :
///
/// struct Incognizable {
///     int a = 0;
///     int b = 0;
/// }


class Incognizable {
public:
    Incognizable() {}
    Incognizable(int a) {
        x = a;
        y = 0;
    }
    Incognizable(int a, int b) {
        x = a;
        y = b;
    }
private:
    int x, y;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}
