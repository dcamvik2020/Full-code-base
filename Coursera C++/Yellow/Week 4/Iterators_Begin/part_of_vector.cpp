#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/// finds first number < 0 and prints
/// previous numbers in reversed order
void PrintVectorPart(const vector<int>& numbers) {
  auto it = find_if(numbers.begin(), 
	       numbers.end(),
	       [](const int x) {
	         return x < 0;
	       });
  /// if (it != numbers.end()) {  /// do not need to do it because
  ///   it++;                     /// in taask we need print all
  /// }                           /// numbers BEFORE it... READ YOUR TASK

  while (it != numbers.begin()) {   /// important : if we write (it-- != ...),
    it--;                           /// even when (it == numbers.begin()) decrement
    cout << *it << " ";             /// will be done ---> it = begin() - 1 ...
  }                                 /// ----> VERY BAD CASE
  
}

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}
