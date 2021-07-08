#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

int main () {
  std::string word, line;
  std::map<std::string, int> cntWords;
  std::ifstream file("input.txt");
  while (getline(file, line)) {
    std::stringstream ss(line);
	while (ss >> word) {
      //std::cout << word << " ";
  	  cntWords[word]++;
      std::cout << cntWords[word] - 1 << " ";
	}
  }
  std::cout << "\n";
  return 0;
}
