#include <iostream>

using namespace std;

class vector {
private:
    int n;
    int *arr;
public:
    vector(): n(0), arr(new int[n]) {
        cout << "Default constructor vector::vector()" << endl;
        // new int[n] --> arr won't be NULL even if n = 0
        // --> don't need to check
    }
    vector(int n0): n(n0), arr(new int[n]) {
        cout << "Constructor vector::vector(int n)" << endl;
    }
    vector(const vector &old): n(old.n), arr(new int[n]) {
        cout << "Copy constructor vector::vector(const vector &old)" << endl;
        for (int i = 0; i < n; i++) {
            arr[i] = old.arr[i];
        }
    }
    int size() const {
        return n;
    }
    ~vector() {
        cout << "Destructor vector::~vector()" << endl;
        delete [] arr; // don't need to check  (arr = NULL)
                       // because "delete [] NULL;" is correct
    }
};

void func1(vector a) {
    cout << "func1: " << a.size() << endl;
}

vector func2() {
    vector res(22);
    cout << "func2: " << res.size() << endl;
    return res;
}

int main() {
    vector stat;
    cout << stat.size() << endl;
    const vector const_stat;
    cout << const_stat.size() << endl;
    vector stat1(10);
    cout << stat1.size() << endl;
    vector stat2 = {20};
    cout << stat2.size() << endl;

    vector *dyn1 = new vector;
    cout << dyn1->size() << endl;
    delete dyn1;
    vector *dyn2 = new vector();
    cout << dyn2->size() << endl;
    delete dyn2;
    vector *dyn3 = new vector(17);
    cout << dyn3->size() << endl;
    delete dyn3;

    vector arr_stat[2];
    cout << arr_stat[0].size() << ", " << arr_stat[1].size() << endl;
    vector *arr_dyn = new vector[2];
    cout << arr_dyn[0].size() << ", " << arr_dyn[1].size() << endl;
    delete[] arr_dyn;

    vector copy1(stat1);
    cout << copy1.size() << endl;
    vector copy2 = stat2;
    cout << copy2.size() << endl;
    vector copy3 = vector(stat1);
    cout << copy3.size() << endl;
    vector copy4(const_stat);
    cout << copy4.size() << endl;

    func1(stat1);
//    vector res = func2();
//    cout << res.size() << endl;
    return 0;
}
