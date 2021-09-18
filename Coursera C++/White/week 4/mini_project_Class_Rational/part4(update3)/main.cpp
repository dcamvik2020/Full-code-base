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

int main() {


    {
         istringstream input("5 / 7");
         cout << "input.str = _|" << input.str() << "|_" << endl;
         Rational r(2, 3);
         input >> r;
         cout << r << endl;
     }

     {
         istringstream input(" / 7");
         cout << "input.str = _|" << input.str() << "|_" << endl;
         Rational r(2, 3);
         input >> r;
         cout << r << endl;
     }

    {
         istringstream input("7/fail");
         cout << "input.str = _|" << input.str() << "|_" << endl;
         Rational r(3, 4);
         input >> r;
         cout << r << endl;
     }

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
        istringstream input("1/2");
        //cout << "input.str if : _" << input.str() << "_\n";
        Rational r;
        cout << "My test output 1: " <<
            r.Numerator() << " " <<
             r.Denominator() << endl;
        /// should be : 0 1
        input >> r;
        cout << "My test output 2: " <<
             r.Numerator() << " " <<
             r.Denominator() << endl;
        /// should be : 1/2
        input >> r;
        cout << "My test output 3: " <<
             r.Numerator() << " " <<
             r.Denominator() << endl;
        /// should be : 1 2
        if (r == Rational{0,0}) {
            cout << "r    is    empty" << endl;
            return 2;
        }
        input = istringstream("3/4");
        input >> r;
        cout << "My test output 4: " <<
             r.Numerator() << " " <<
             r.Denominator() << endl;
        /// should be :3 4
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
