#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  std::string fname("/home/melnikov_viktor/M");
  struct stat buf;
  int stat_res;
  if ((stat_res = stat(fname.c_str(), &buf)) == -1) {
    perror("stat");
  }
  return 0;
}
