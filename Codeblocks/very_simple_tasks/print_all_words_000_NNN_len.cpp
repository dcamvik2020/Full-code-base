#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

void permut_1_N(unsigned N, unsigned len);
void Print(const vector<int> & v);

int main() {
	
	unsigned N, len;
	cin >> N >> len;
	permut_1_N(N, len);
	return 0;
}

/// prints all words from 00...00 to (N-1)(N-1)...(N-1)(N-1) (length = len)
void permut_1_N(unsigned N, unsigned len) {
    if (N == 0) return;
    
    vector<int> v (len, 0) ;
    unsigned count_N = 0;
    do {
        Print(v);
        
        /// new permutation
        unsigned j = len;
        for ( ; j && v[j - 1] == int(N - 1); count_N++, --j);
        if (j) {
	    ++v[j - 1];
            for (unsigned k = j; k < len; ++k) v[k] = 0;
            count_N -= (len - j);
	}
    } while (count_N < len);
    cout << endl;
}

void Print(const vector<int> & v) {
    bool first = true;
    for (const auto & x : v) {
        if (first == false) {
	    //cout << " ";	
	}
	cout << x;
	first = false;
    }
    cout << " ";
}
