#include <iostream>
#include <math.h>

using namespace std;

///    PART  3  : operators *, /
///    Garanted: type int is evrywhere.

int GCD(int a, int b) {
    while (b) {
        if (a >= b) {
            a = a % b;
        }
        swap(a, b);
    }
    return a;
}

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int p, int q) {
        /// GCD
        if (q < 0) {
            p *= -1;
            q *= -1;
        }
        int gcd = GCD(abs(p), abs(q));
        numerator   = gcd ? (p / gcd) : p;
        denominator = gcd ? (q / gcd) : q;
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

bool operator == (Rational x, Rational y) {
    if (x.Denominator() == y.Denominator()) {
        return x.Numerator() == y.Numerator();
    }
    return x.Denominator() == y.Denominator();
}

Rational operator + (Rational x, Rational y) {
    int a = x.Numerator(), b = x.Denominator();
    int c = y.Numerator(), d = y.Denominator();
    return {a*d + b*c,
             + b*d};
}

Rational operator - (Rational x, Rational y) {
    int a = x.Numerator(), b = x.Denominator();
    int c = y.Numerator(), d = y.Denominator();
    return {a*d - b*c,
             + b*d};
}

Rational operator * (Rational x, Rational y) {
    return {x.Numerator() * y.Numerator(), x.Denominator() * y.Denominator()};
}

Rational operator / (Rational x, Rational y) {
    return {x.Numerator() * y.Denominator(), x.Denominator() * y.Numerator()};
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
