#include <iostream>
#include <complex>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
#include "Complex.h"

/*
#define OP2__(C, A, x, B) \
    C = A x B; \
    cout << A << " "#x" " << B << " = " << C << endl; \


#define CHECK \
    cout << endl << (fabs(c.Re() - c0.real()) < 1e-6 && fabs(c.Im() - c0.imag()) < 1e-6 ? "PASSED" : "!!! FAILED !!!") << endl << endl; \


#define OP2_(x, A1, B1, C1, A0, B0, C0) \
    OP2__(C1, A1, x, B1); \
    OP2__(C0, A0, x, B0); \
    CHECK; \


#define OP2(x) \
    OP2_(x, a1, b1, c, a0, b0, c0); \
    OP2_(x, a1, d, c, a0, d, c0); \
    OP2_(x, d, b1, c, d, b0, c0); \


#define OP_2__(C, A, x, B) \
    cout << A << " "#x" " << B << endl; \
    C = A x B; \
    cout << A << " "#x" " << B << " = " << C << endl; \


#define OP_2_(x, A1, B1, C1, A0, B0, C0) \
    _##A1 = A1; \
    OP_2__(C1, _##A1, x, B1); \
    _##A0 = A0; \
    OP_2__(C0, _##A0, x, B0); \
    CHECK; \


#define OP_2(x) \
    OP_2_(x, a, b1, c, a0, b0, c0); \
    OP_2_(x, a, d, c, a0, d, c0); \


#define OP1__(C, x, A) \
    C = x A; \
    cout << C << " = "#x"(" << A << ")" << endl; \


#define OP1_(x, A1, C1, A0, C0) \
    OP1__(C1, x, A1); \
    OP1__(C0, x, A0); \
    CHECK; \


#define OP1(x) \
    OP1_(x, a1, c, a0, c0); \
*/

int main(void) {
/*
    Complex a, b, c, _a;
    const Complex &a1 = a, &b1 = b;
    double d;
    cin >> a >> b >> d;
    complex<double> a0(a.Re(), a.Im()), b0(b.Re(), b.Im()), c0, _a0;
*/
//    c = a + b;
//    cout << a << " + " << b << " = " << c << endl;

    /*OP2(+);
    OP2(-);
    OP2(*);
    OP_2( = );
    OP_2( += );
    OP_2( -= );
    OP_2( *= );
    OP_2( /= );
    OP1(+);
    OP1(-);*/

    Complex a, b;
    cin >> a;
    cout << (b = Complex(1, 0) / a) << endl;
    cout << b * a << endl;
    return 0;
}


