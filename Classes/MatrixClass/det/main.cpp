#include <iostream>

#include "Matrix.h"

int det(const Matrix& A) {
    int n = A.Rows(), m = A.Cols();

    if (n == 0 || m == 0 || n != m)
        throw std::invalid_argument("Error size of matrix");
    if (n == 1)
        return A[0][0];


    int res = 0, i, k = 1; /// (-1)^n
    /// smaller matrix, (n-1)*(n-1) -->
    /// use standard formula for det(A)
    Matrix p(n - 1, n - 1);

    for (i = 0; i < n; i++) {
        int a, b, dx, dy;
        dy = 0;
        for (a = 0; a < n - 1; a++) {
            dx = 0;
            if (a == 0) {
                dy = 1;
            }
            for (b = 0; b < n - 1; b++) {
                if (b == i)
                    dx = 1;
                p[a][b] = A[a+dy][b+dx];
            }
        }
        res += k * A[0][i] * det(p);
        k = -k; /// like in standard formula
    }
    return res;
}

int main() {
    Matrix A;
    cout << "Matrix A:" << endl;
    cin >> A;
    cout << "det(A) = " << A.det() << endl;
    return 0;
}
