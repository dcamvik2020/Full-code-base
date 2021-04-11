#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

///    PART  4  : operators <<, >>
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
    return {a*d + b*c, b*d};
}

Rational operator - (Rational x, Rational y) {
    int a = x.Numerator(), b = x.Denominator();
    int c = y.Numerator(), d = y.Denominator();
    return {a*d - b*c, b*d};
}

Rational operator * (Rational x, Rational y) {
    return {x.Numerator() * y.Numerator(), x.Denominator() * y.Denominator()};
}

Rational operator / (Rational x, Rational y) {
    return {x.Numerator() * y.Denominator(), x.Denominator() * y.Numerator()};
}

istream& operator >> (istream& input, Rational& x) {
    /// EOF    <--->     End Of File
    /// EOF     --->     no changes
    /// input.peek() ----> check the next character
    /// input.eof()
    /// input.tellg() ----> current position
    //cout << "in fuction operator >> input.peek = _" << input.peek() << "_\n";
    if (input.peek() != -1) {
        int a, b;
        input >> a;
        input.ignore(1); ///   x = a/b
        input >> b;
        x = Rational{a, b};
    }
    return input;
}

ostream& operator << (ostream& output, const Rational& x) {
    output << x.Numerator();
    output << "/";
    output << x.Denominator();
    return output;
}

int main() {
    /* {
         Rational r;
         cin >> r;
         cout << r;
     }*/

    {
        stringstream output;
        output << Rational(-6, 8) + Rational(6, 8);
        if (output.str() != "0/1") {
            cout << output.str() << endl;
            cout << "It should be written as \"0/1\"" << endl;
            return 1;
        }
    }

    {
        istringstream input;
        //cout << "input.str if : _" << input.str() << "_\n";
        Rational r;
        //cout << "My test output 1: " <<
        //    r.Numerator() << " " <<
        //     r.Denominator() << endl;
        /// chould be : 0 1
        input >> r;
        //cout << "My test output 2: " <<
        //     r.Numerator() << " " <<
        //     r.Denominator() << endl;
        /// chould be : 0 1
        if (r == Rational{0,0}) {
            cout << "r    is    empty" << endl;
            return 2;
        }
    }

    {
        stringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        stringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << r1 << "             " << r2 << endl;
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
