#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void qsort(int * a, unsigned n);

int main() {
    unsigned n;
    cin >> n;

    int * a = new int[n];
    for (unsigned i = 0; i < n; ++i) {
	cin >> a[i];
    }
    qsort(a, n);
    for (unsigned i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }
    cout << endl;
    delete [] a;
    return 0;
}

void qsort(int * a, unsigned n) {
    if (n < 2) {
        return;
    }


    int buf, middle = a[n / 2];
    unsigned mid = n / 2;

  /*  
for (unsigned i = 0; i < n; ++i) cout << " ";
cout << "was : " << "(mid = " << mid << ")  ";
for (unsigned i = 0; i < n; ++i) cout << a[i] << " ";
cout << endl;
*/
    
    /// partition
    for (unsigned i = 0, j = n - 1; i < j; ) {
        while (i < n - 1 && a[i] < middle) {
            ++i;
	}
	while (j > 0 && a[j] > middle) {
            --j;
	}

	if (j <= i) {
	    break;
        }

        buf = a[i];
	a[i] = a[j];
	a[j] = buf;
        if (a[i] == middle) mid = i;
	if (a[j] == middle) mid = j;
	/*if (a[i] != middle)*/       //++i; ---> don't catch the situation: if (..) mid = i --->  
	/*if (a[j] != middle)*/       //--j; ---> mid = i , --> ++i, --> but a[mid] > a[i] ... BAD !!
    } 
/*
for (unsigned i = 0; i < n; ++i) cout << " ";
cout << "now : " << "(mid = " << mid << ")  ";
for (unsigned i = 0; i < n; ++i) cout << a[i] << " ";
cout << endl;
*/
    qsort(a, mid);
    qsort(a + mid, n - mid);
}
