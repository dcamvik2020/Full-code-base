#include <iostream>
#include <dirent.h>

int main() {
  std::string dirname;
  std::cin >> dirname;
  DIR * dir;
  if ((dir = opendir(dirname.c_str())) == nullptr) {
    perror("opendir");
    return 0;
  }
  struct dirent * pEntry;
  while ((pEntry = readdir(dir))) {
    std::cout << pEntry -> d_name << std::endl;
  }
  return 0;
}
