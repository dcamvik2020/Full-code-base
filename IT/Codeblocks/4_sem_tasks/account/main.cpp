#include <iostream>

using namespace std;

class Account {
private:
    int balance, limit;
public:
    Account(int limit) {
        this->limit = limit;
        if (limit > 0) {
            balance = limit;
        } else {
            balance = 0;
        }
    }
    int get_balance() {
        return balance;
    }
    void change_balance(int sum) {
        if (balance + sum < limit) {
            balance = limit;
        } else {
            balance += sum;
        }
    }
};

int main(void) {
    int limit, sum;
    cin >> limit;
    Account acc(limit);
    cout << acc.get_balance() << endl;
    while (cin >> sum) {
    acc.change_balance(sum);
        cout << acc.get_balance() << endl;
    }
    return 0;
}
