#include <iostream>

#include "Matrix.h"

Matrix multiply(const Matrix& A, const Matrix& B) {
    int n = A.Rows(), m = A.Cols(), x = B.Rows(), y = B.Cols();

    if (m != x) {
        throw std::invalid_argument("");
    }

    Matrix C(n, y);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main()
{
    /// input(sizes)
    Matrix A, B, C;
    cout << "Matrix A:" << endl;
    cin >> A;
    cout << "\nMatrix B:" << endl;
    cin >> B;

    ///output
    cout << "\nThe result is C:" << endl;
    //cout << multiply(A, B) << endl;
    cout << A * B << endl;
    return 0;
}
