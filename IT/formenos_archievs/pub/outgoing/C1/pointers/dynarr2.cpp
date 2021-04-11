#include <iostream>

using namespace std;

int main(void) {
	int i, j, n, m, **A;
	cin >> n >> m;
	//alloc
	A = new int*[n];
	for (i = 0; i < n; i++)
		A[i] = new int[m];
	//use
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> A[i][j];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
	//free
	for (i = 0; i < n; i++)
		delete[] A[i];
	delete[] A;
	return 0;
}
