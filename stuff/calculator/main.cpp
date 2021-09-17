#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void CorrectString(const char* tmp, char* s);
double SplitToBrackets(char *s);
double CalcRec(char *s);

int main() {
    //char c;
    char tmp[200], s[200];
    cin.getline(tmp, 199);
    CorrectString(tmp, s);
    cout << SplitToBrackets(s) << endl;
    return 0;
}

void CorrectString(const char* tmp, char* s) {

    unsigned size = 0;
    /// detect whitespaces
    for (unsigned i = 0; tmp[i]; ++i) {
        if (tmp[i] == ' ') continue;
        s[size] = tmp[i];
        ++size;
    }
    s[size] = '\0';

    /// check bracket balance
    int balance = 0;
    for (unsigned i = 0; s[i]; ++i) {
        if (s[i] == '(') ++balance;
        if (s[i] == ')') --balance;
    }
    if (balance) {
        cout << "Wrong bracket balance" << endl;
        exit(-1);
    }

    /// check: there aren't digits before '(' and after ')'
    for (unsigned i = 0; s[i]; ++i) {
        if ((s[i] == '(' &&    i   && '0' <= s[i-1] && s[i-1] <= 9) ||
            (s[i] == ')' && s[i+1] && '0' <= s[i+1] && s[i+1] <= 9)) {
            cout << "No operation between bracket and digit" << endl;
            exit(-1);
        }
    }


    if (s[0] == '*' || s[0] == '/' || s[size - 1] == '+' ||
        s[size - 1] == '-' || s[size - 1] == '*' || s[size - 1] == '/') {
      cout << "Operation before or after expression" << endl;
      exit(-1);
    }

    /// check _+_ , _-_ , _*_ , _/_ (binary ops)
    for (unsigned i = 0; s[i]; ++i) {
        /// consider only binary operations
        if (s[i] != '+' && s[i] != '-' &&
            s[i] != '*' && s[i] != '/') {
            continue;
        }

        /// it mustn't have neighbours like itself
        if (s[i-1] == '+' || s[i-1] == '-' ||
            s[i-1] == '*' || s[i-1] == '/' ||
            s[i+1] == '+' || s[i+1] == '-' ||
            s[i+1] == '*' || s[i+1] == '/') {
            cout << "Wrong arithmetic expression" << endl;
            exit(-1);
        }
    }
}

double SplitToBrackets(char *s) {
    /// brackets are correct, expression too
    int counter = 0;
    int brackets = 0;
    //char *p;
    unsigned i;

    /// find last bracket
    for (i = strlen(s) - 1; i > 0 && brackets == 0; --i) {
        if (counter == 0 && 
	    ((s[i] == '+') || (s[i] == '-') || 
	     (s[i] == '*') || (s[i] == '/'))) break;
	if (s[i] == '(') {
            ++counter;
        }
        if (s[i] == ')') {
            --counter;
            if (counter == 0) {
                ++brackets;
            }
        }
    }

    /// split for 2 parts, count
    if (s[i] == '+') {
        s[i] = '\0';
        return SplitToBrackets(s) + CalcRec(s + i + 1);
    }
    if (s[i] == '-') {
        s[i] = '\0';
        return SplitToBrackets(s) - CalcRec(s + i + 1);
    }
    if (s[i] == '*') {
        s[i] = '\0';
        return SplitToBrackets(s) * CalcRec(s + i + 1);
    }
    if (s[i] == '/') {
        s[i] = '\0';
        return SplitToBrackets(s) / CalcRec(s + i + 1);
    }
    return CalcRec(s + i); /// if no opeartion ---> calculate this part
}

/// !! no folded brackets within external
///    brackets and it's correct expression
double CalcRec(char *s) {
    char *p;
    if (s[0] == '(') {            /// detect brekets
        p = strrchr(s, ')');      /// on the board
        *p = '\0';                /// of the expression
        return CalcRec(s+1);      /// kept in s
    }
    if ((p = strrchr(s, '+')) != NULL) {
            *p = '\0';
            return CalcRec(s) + CalcRec(++p);
    }
    if ((p = strrchr(s, '-')) != NULL) { //search for last '-'
            *p = '\0';
            return CalcRec(s) - CalcRec(++p); //if "s" was "-X" (and now is ""), then CalcRec(s) returns 0
    }
    if ((p = strrchr(s, '*')) != NULL) {
            *p = '\0';
            return CalcRec(s) * CalcRec(++p);
    }
    if ((p = strrchr(s, '/')) != NULL) {
            *p = '\0';
            return CalcRec(s) / CalcRec(++p); //// ODZ !!!
    }
    if ((p = strrchr(s, '^')) != NULL) {
            *p = '\0';
            return pow(CalcRec(s), CalcRec(++p)); //// ODZ !!!
    }
    if ((p = strrchr(s, '#')) != NULL) {
            *p = '\0';
            return sqrt(CalcRec(++p)); //// ODZ !!!
    }
    return atof(s);  // "s" must be correct floating-point number
}



