#include <iostream>
#include <string_view>

using namespace std;

int main() {
	
  string str = "sfsbdlgbs";
  string_view s(str); /// ... it's like a string ... but it isn't a string
  cout << s << endl;  /// it's like a reference to string with pointer and size
  return 0;           /// PS : -std=c++1z    is important
}
