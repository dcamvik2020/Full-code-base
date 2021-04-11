#include <iostream>
#include "unit.h"

using namespace std;

int N;

int main() {
    cin >> N;
    
    int *a = new int[N];
    for (int i = 0; i < N; ++i) {
        a[i] = i;
    }
    
    //a[N] = 10;
    // 
    print5();

    delete [] a;
    return 0;
}
