#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned RandomizedPartition (int * a, unsigned n);
int OrderStat (int * a, unsigned n, unsigned k);

int main() {
    srand(time(NULL));
    /// n = elements, k = ordered statistics
    unsigned n, k;
    cin >> n >> k;

    int * a = new int[n];
    for (unsigned i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << OrderStat(a, n, k - 1) << endl;
    return 0;
}

int OrderStat (int * a, unsigned n, unsigned k) {
    /// randomized partition
    unsigned core = RandomizedPartition(a, n);
    
    /// core, k  --->  INDEXES   --->    0 <= {core, k} < n
    if (core == k) {
        return a[core];
    } else if (core < k) {
        return OrderStat(a + core + 1, n - core - 1, k - core - 1);
    } else {
        return OrderStat(a, core, k);
    }
}

unsigned RandomizedPartition (int * a, unsigned n) {
    unsigned core = rand() % n; /// core element for partition
    int root = a[core];
    int buf;

    for (unsigned i = 0, j = n - 1; i < j; ) {
        while (i < n - 1 && a[i] < root) {
	    ++i;
	}
	while (j > 0 && a[j] > root) { /// >, not >= because we can go
	    --j;                       /// across root --> problem !!
	}

	if (i >= j) {
	    break;
	}

	buf = a[i];
	a[i] = a[j];
	a[j] = buf;

	if (root == a[i]) core = i;
        if (root == a[j]) core = j;
    }

    return core;
}
