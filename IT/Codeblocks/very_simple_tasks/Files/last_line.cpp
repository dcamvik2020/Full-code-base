#include <iostream>
#include <fstream>

#include <functional>

#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

std::string 
last_line_if(std::fstream & file, const std::function
        <bool(const std::string &)> & predicate = {
	        [](const std::string &){return true;}  }) {
  std::string prev_line, line;
  do {
    if (predicate(line)) prev_line = line;
  } while (getline(file, line));
  return prev_line;
}

std::string last_line(std::ifstream & file) {
  std::string res;
  
  return res;
}

int main() {
  std::string file_name;
  std::cin >> file_name;
  struct stat stat_buf;
  if (stat(file_name.c_str(), &stat_buf) == -1) {
    perror("stat");
    return 0;
  }
  std::fstream file(file_name);
  /*auto predicate = [] (const std::string & s) -> bool {
    return s[0] == 'i';
  };*/
  std::cout << last_line(file) << std::endl;
  return 0;
}
