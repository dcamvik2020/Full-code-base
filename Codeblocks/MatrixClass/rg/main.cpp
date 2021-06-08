#include <iostream>

#include "Complex.h"
#include "Matrix.h"

//#define cor0(x) (-1e-10 < (x) && (x) < 1e-10 ? 0 : (x))


int main() {
    //cout << Complex(3, 5) * Complex(2, 1) << endl;
    //return 0;

    unsigned n;
    cout << "size o vectors : ";
    cin >> n;
    //Matrix<Complex> a(n, 1), b(1, n); 
    Matrix<double> a(n, 1), b(1, n);
    cout << "vector 1 (column):\n";
    for (unsigned i = 0; i < n ; ++i) {
        cin >> a[i][0];
    }
    cout << "\nvector 2 (row):\n";
    for (unsigned i = 0; i < n ; ++i) {
        cin >> b[0][i];
    }

    cout << "\nmatrix : 1*2 = " << endl;
    cout << a*b << endl;




/*
    Matrix<double> A;
    cout << "Matrix A:" << endl;
    cin >> A;

    A.transpose();
    cout << "A.TRANSPOSED: " << endl
         << A << endl;

    A.transpose();
    cout << "A.TRANSPOSED^2: " << endl
         << A << endl;


    //cout << "A.TRANSPOSED^2: " << endl
    //     << A.transposed() << endl;
*/



/*
    Matrix<double> A, B;
    cout << "Matrix A:" << endl;
    cin >> A;

    cout << "Matrix B:" << endl;
    cin >> B;

    cout << (A == B) << endl;
*/



/*
    Matrix<Complex> A;
    cout << "Matrix A:" << endl;
    cin >> A;
    Matrix<Complex> B = A.inversed();
    cout << "\nB = inversed(A):" << endl;
    cout << B << endl;

    Matrix<Complex> C = A * B;
    C.MakeAccuracy();
    cout << "\nA * B:" << endl;
    cout << C << endl;

    cout << "rg(A) = " << rg(A) << endl;

    cout << "Matrix A:" << endl;
    cin >> A;
    //cout << endl << "rg(A) = " << rg(A) << endl;
    cout << endl << "rg(A) = " << A.rg() << endl;



    Vector<int> v(2);
    Matrix<int> A(2, 3, 4);
    //Mastrix<int> A(6, 7, 4);
    cout << "A :\n____" <<  A << endl << "_____\n";
    //A.resize(3, 4);
    cout << "A :\n____" <<  A << endl << "_____\n";

    //A.resize(5, 4);
    A.add_column(v);
    cout << "A :\n____" <<  A << endl << "_____\n";
*/




    return 0;
}


/*
#define new_cor0(x) (-1e-10 < (x) && (x) < 1e-10 ? 0 : (x))

void change_column(Matrix<double>& mtr, int j) {
    int N = mtr.Rows() - 1;
    if (j == 0) {
        std::swap(mtr[N], mtr[0]);
    } else {
        std::swap(mtr[N], mtr[j-1]);
        std::swap(mtr[N], mtr[j]);
    }
}

int main() {
    int N, i, j;
    double x, x0;
    cout << "Nuber of equations: ";
    cin >> N;
    Vector<double> b(N);
    Matrix<double> numbers(N, N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> numbers[j][i];
        }
        cin >> b[i];
    }

    ///check and the search of solutions
    x0 = numbers.det();
    cout << "                 det is computed" << endl;

    numbers.resize(N+1, N );
    numbers[N] = b;
    //numbers.add_column(b);
    cout << "                  b  is added\n\n" << endl;
    cout << "x0 = " << x0 << endl;
    if (x0) {
        for (i = 0; i < N; i++) {
            cout << "\n\ncome in " << i;
            Matrix<double> tmp(numbers);
            //cout << "     try to change column" << endl;
            change_column(tmp, i);
            //cout << "     try to resize" << endl;
            tmp.resize(N, N);
            cout << "     resized tmp:"
                 << tmp << endl;
            cout << "     det = " << tmp.det();
            cout << endl;
            x = tmp.det() / x0;
            //x = (double) determinant(tmp, N) / x0;
            cout << i << ": " << new_cor0(x) << endl;
        }
    }
    else {
        cout << "No roots" << endl;
    }
    return 0;
}
*/

