#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <vector>

#include <exception>

using namespace std;

///    Extra  :   division by 0 exception
///    Garanted: all that was garanted earlier.

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
        /// Exception
        if (q == 0) {
            throw invalid_argument("constructor error : denominator = 0");
        }

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

bool operator == (const Rational& x, const Rational& y) {
    if (x.Denominator() == y.Denominator()) {
        return x.Numerator() == y.Numerator();
    }
    return x.Denominator() == y.Denominator();
}

Rational operator + (const Rational& x, const Rational& y) {
    int a = x.Numerator(), b = x.Denominator();
    int c = y.Numerator(), d = y.Denominator();
    return {a*d + b*c, b*d};
}

Rational operator - (const Rational& x, const Rational& y) {
    int a = x.Numerator(), b = x.Denominator();
    int c = y.Numerator(), d = y.Denominator();
    return {a*d - b*c, b*d};
}

Rational operator * (const Rational& x, const Rational& y) {
    return {x.Numerator() * y.Numerator(), x.Denominator() * y.Denominator()};
}

Rational operator / (const Rational& x, const Rational& y) {
    if (y.Numerator() == 0) {
        throw domain_error("div by zero");
    }
    return {x.Numerator() * y.Denominator(), x.Denominator() * y.Numerator()};
}

bool IsNumber(const string& s) {
    int i;
    for (i = 0; s[i] == ' '; ++i);
    for (; s[i]; ++i) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

istream& operator >> (istream& input, Rational& x) {

    char c;
    int a, b;
    if (input.tellg() != -1) {
        input >> a;
        if (input.tellg() != -1) {
            input >> c;
            if (input.tellg() != -1) {
                input >> b;
                if (input.fail() == false) {
                    x = Rational(a, b);
                }
            }
        }
    }
    return input;

/// VERSION 2   ---   OK, but not so nice and breifly
/*
    if (input.tellg() == -1) {
        return input;
    }
    input >> a;
    if (input.tellg() == -1) {
        return input;
    }
    input >> c;
    if (input.tellg() == -1) {
        return input;
    }
    input >> b;
    if (input.fail()) {
        return input;
    }
    x = Rational(a, b);
    return input;
*/

/// VERSION 1   ----    complete fail
/*
    string line;
    getline(input, line);
    stringstream stream;
    stream << line;
    if (stream.str() == "") {
        return input;
    }
    /// if stream is empty ---> return
    if (!input || input.peek() == -1 ||
                  input.peek() == '\n' ||
                  input.tellg() == -1) {
        return input;
    }*/
/*
    int a;
    string b;
    char c;
    //input >> a;
    stream >> a;
    //if (input.eof() == false) {
    if (stream.str() != "") {
        //input >> c;
        stream >> c;
        if (c == '/') {
            //input >> b;
            stream >> b;
            if (IsNumber(b)) {
                x = Rational{a, stoi(b)};
            }
        }
    }
    input << line[stream.tellg()];
    return input;
*/


}

ostream& operator << (ostream& output, const Rational& x) {
    output << x.Numerator() << "/" << x.Denominator();
    return output;
}

bool operator < (const Rational& x, const Rational& y) {
    /// it is not clear
    ///return x.Numerator() * y.Denominator() < x.Denominator() * y.Numerator();

    /// it is clear
    return (x-y).Numerator() < 0;
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
        cout << "Invalid argument" << endl;
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
        cout << "Division by zero" << endl;
    }

    cout << "OK" << endl;
    return 0;
}
