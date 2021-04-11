#include <iostream>
#include <fstream>

#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  std::string file_name;
  std::cin >> file_name;
  struct stat stat_buf;
  if (stat(file_name.c_str(), &stat_buf) == -1) {
    perror("stat");
    return 0;
  }
  std::fstream file(file_name);
  std::string line;
  while (getline(file, line)) {
    std::cout << line << std::endl;
  }
  
  return 0;
}
