#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

int main () {
  std::string word, line;
  std::map<std::string, int> cntWords;
  std::ifstream file("input.txt");

  std::string famousword;
  while (getline(file, line)) {
    std::stringstream ss(line);
  
    while (ss >> word) {
      //std::cout << word << " ";
      cntWords[word]++;
      //std::cout << cntWords[word] << "\n";
  
      if (famousword == "")
        famousword = word;
      if (cntWords[word] > cntWords[famousword])
        famousword = word;
      else if (cntWords[word] == cntWords[famousword]) {
        if (word < famousword)
		  famousword = word;
	  }
    }
  }
  std::cout << famousword << "\n";
  return 0;
}

