#include <iostream>
#include "Vector.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#define max(a, b) (((a) >= (b)) ? (a) : (b))
#define min(a, b) (((a) >= (b)) ? (b) : (a))
unsigned LCS (const std::string & s1, const std::string & s2);

int main() {
    std::string S1, S2;
    cin >> S1 >> S2;
    cout << LCS (S1, S2) << endl;
    return 0;
}

unsigned LCS (const std::string & s1, const std::string & s2) {
    unsigned i, j, m = s1.size(), n = s2.size();
    Vector<Vector<int>> lcs;
    lcs.resize(m + 1);
    for (i = 0; i <= m; ++i) {
        lcs[i].resize(n + 1);	    
    }
    
    /// i -> s1, j -> s2
    for (i = 0; s1[i]; ++i) {
        for (j = 0; s2[j]; ++j) {
            if (s1[i] == s2[j]) {
                lcs[i+1][j+1] = 1 + lcs[i][j];
	    } else {
                if (lcs[i][j+1] >= lcs[i+1][j]) {
		    lcs[i+1][j+1] = lcs[i][j+1];
		} else {
                    lcs[i+1][j+1] = lcs[i+1][j];
		}
	    }
	    //cout << lcs[i][j] << " " ;
	}
	//cout << endl;
    }
    //cout << endl;

    /// find the LCS
    unsigned k = 0, LCS_len = lcs[m][n];
    std::string LCS(LCS_len, '\0');
    for (i = m, j = n; k < LCS_len;) {
        if (s1[i-1] == s2[j-1] && lcs[i][j] == lcs[i-1][j-1] + 1) {
	    LCS[k] = s1[i-1];
	    k++;
	    --i;
	    --j;
	} else if (lcs[i][j] == lcs[i-1][j]) {
            --i;
	} else if (lcs[i][j] == lcs[i][j-1]) {
            --j;
	}
    }
    for (i = 0; i < LCS_len / 2; ++i) {
        std::swap(LCS[i], LCS[LCS_len - i - 1]);
    }
    cout << "LCS : "; 
    cout << LCS << endl;
    cout << "start (s1, i) : " << i << "    s1[i] = " << s1[i] << endl;
    cout << "lcs[m][n] = ";
    return lcs[m][n];
}
