#include <iostream>
#include <string.h>

using namespace std;

double defolt(int deposit, int exch_rate) {
    return deposit * exch_rate;
}

double defolt(int deposit = 0, double exchg_rate = 30,
              const char *name = "Rumpelstilzchen", unsigned denom = 3,
              double deval = 4, double infl = 84.4, int tax = 13) {
    unsigned name_len = strlen(name);
    unsigned extra_length_name = (name_len > 6) ? (name_len - 6) : 0;
    double res;
    res = deposit * exchg_rate * (1 - tax / 100.0);
    res = res / (1 + infl / 100) / deval;
    for (; denom; denom--) {
        res /= 10;
    }
    res *= 1 - extra_length_name / 100.0;
    return res;
}

int main()
{
    printf("%.2lf\n%.2lf\n",
           defolt(1000000, 60),
           defolt(1000000, 60, "Emelya",
            0, 2, 0, 0));
    return 0;
}
