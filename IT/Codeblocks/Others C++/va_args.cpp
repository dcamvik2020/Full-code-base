#include <iostream>
#include <cstdarg>

void doSmth(int count, ...);

int main() {
  doSmth(3, 2, 5.6, "abc");
  return 0;
}

void doSmth(int count, ...) {
  va_list list;
  count = 0; /// not used anymore

  /// 1: va_list, 2: last parameter not in ellipsis "..."
  va_start(list, count);
  std::cout << va_arg(list, int) << std::endl;
  std::cout << va_arg(list, double) << std::endl;
  std::cout << va_arg(list, char*) << std::endl;
  va_end(list);
}
