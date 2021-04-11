#include "Vector.h"
#include "usage_cmd.h"

/// In programmer's responsibility:
/// - remember about Vector sizes (he can change it as he wants at any time)
/// - remember about Vector's aim (what variable responses)

int main() {
  
  Usage();
  Vector<int> v;
  while (1) {
    std::cout << " >>> ";
    int result = ParseCommand(v);
    if (result == 1) {
      return 0;
    }
    if (result == -1) {
      std::cerr << "         !! Wrong command !!" << std::endl;
    }
  }

  Vector<int> a(3), b(4);
  std::cout << "\n\na :\n" << a << std::endl;
  std::cout << "\nb :\n" << b << std::endl;
  std::cout << "\n (a == b) : " << (a == b) << std::endl;

  std::vector<int> t = {3, 1, 4, 6, 6};
  std::cout << "\n\na :\n" << a << std::endl;
  std::cout << "\nb :\n" << t << std::endl;
  std::cout << "\n (a == b) : " << (a == t) << std::endl;

  return 0;
}
