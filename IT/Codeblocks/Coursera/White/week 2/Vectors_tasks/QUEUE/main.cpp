#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void come(vector<bool>& v, int k) {
    if (k > 0) {
        for (int i = 0; i < k; ++i) {
            v.push_back(false);
        }
    } else {
        for (int i = 0; i < -k; ++i) {
            v.pop_back();
        }
    }
}

int main() {
    int Q, i, k;
    cin >> Q;
    string cmd;
    vector<bool> v;/// i->condition:
                     /// 1 - worried, 0 - quiet
    for (; Q; --Q) {
        cin >> cmd;
        if (cmd == "COME") {
            cin >> k;
            ///come(v, k);  ---> a too long way
            v.resize(v.size() + k, false);
        } else if (cmd == "WORRY") {
            cin >> i;
            v[i] = true;
        } else if (cmd == "QUIET") {
            cin >> i;
            v[i] = false;
        } else if (cmd == "WORRY_COUNT"){
            cout << count(begin(v), end(v), true) << endl;
        } else {
            Q++;
        }
    }
    return 0;
}
