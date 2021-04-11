#include <iostream>
#include <string_view>

using namespace std;

int main() {
  string_view s("hey, hop, lalley");
  cout << "firstly, s was : \"" << s  << "\"" << "\n";
  s = s.substr(s.find(' ') + 1);
  cout << "then we found the first space : \"" << s << "\"" << "\n";
  cout << "also ... we may know the size of string_view s : " << sizeof(s) << "\n";
  return 0;
}
