#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

void bruteforce(char start, char finish, unsigned len);
void Print(const vector<char> & v);

int main() {

  char start, finish;
  unsigned len;
  
  cout << "start char : ";
  cin >> start;
  cout << "finish char : ";
  cin >> finish;
  cout << "length of password : ";
  cin >> len;
  cout << endl;

  bruteforce(start, finish, len);
  
  return 0;
}




/// prints all words from 00...00 to (N-1)(N-1)...(N-1)(N-1) (length = len)
void bruteforce(char start, char finish, unsigned len) {
    if (len == 0) return;
    
    vector<char> v (len, start) ;
    unsigned count_finish = 0;
    do {
        //Print(v);
        
        /// new permutation
        unsigned j = len;                                         /// PAY ATTENTION :
        for ( ; j && v[j - 1] == finish; count_finish++, --j);    ///   j   --> (j+1)
        if (j) {                                                  /// len-1 -->  len
	    ++v[j - 1];
            for (unsigned k = j; k < len; ++k) v[k] = start;
            count_finish -= (len - j);
	}
    } while (count_finish < len);
    
    cout << endl;
}

void Print(const vector<char> & v) {
    for (const char & x : v) {
	cout << x;
    }
    cout << endl;
}
