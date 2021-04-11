#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
  std::string filename;
  std::cin >> filename;
  std::ifstream(filename.c_str());
  struct stat statbuf;
  if (stat(filename.c_str(), &statbuf) == -1) {
    perror("stat");
  } else {
    std::cout << statbuf.st_size << std::endl;
  }
  return 0;
}
