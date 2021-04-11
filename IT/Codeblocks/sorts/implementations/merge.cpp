#include <iostream>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;

void merge(int * a, unsigned n);

int main() {
    srand(time(NULL));
    unsigned n;
    cin >> n;
    int * a = new int[n]();
    for (unsigned i = 0; i < n; ++i) {
        cin >> a[i];
    }
    merge(a, n);
    for (unsigned i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }
    cout << endl;
    delete [] a;
    return 0;
}

void merge(int * a, unsigned n) {
    
    int buf;
    if (n == 1) {
	return;
    } else if (n == 2) {
	if (a[0] > a[1]) {
            buf = a[0];
	    a[0] = a[1];
	    a[1] = buf;
	}
	return;
    }
	
    
    
    unsigned l, r;
    l = (n % 2) ? (n/2 + 1) : (n / 2);
    r = n / 2; 
    int * left  = new int[l];
    int * right = new int[r];
    for (unsigned i = 0; i < l; ++i) {
	left[i] = a[i];
    }
    for (unsigned j = 0; j < r; ++j) {
        right[j] = a[l + j];
    }

    merge(left, l);
    merge(right, r);

    for (unsigned i = 0, j = 0; i + j < n; ) {
	if (i == l) {
	    a[i + j] = right[j];
            ++j;	    
	} else if (j == r) {
            a[i + j] = left[i];
	    ++i;
	} else {
            /// choose the mpst element
	    if (left[i] > right[j]) {
                a[i + j] = right[j];
		j++;
	    } else {
                a[i + j] = left[i];
		i++;
	    }
	}
    }
    delete [] left;
    delete [] right;
}
