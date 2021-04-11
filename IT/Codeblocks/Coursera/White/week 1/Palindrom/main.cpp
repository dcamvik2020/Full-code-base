#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsPalindrom(string w) {
    int len = 0;
    for (; w[len]; ++len);
    for (int i = 0; i < len / 2; i++) {
        if (w[i] != w[len - i - 1]) return false;
    }
    return true;
}

vector<string> PalindromFilter(vector<string> v, int minLength) {
    vector<string> out;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].size() >= minLength && IsPalindrom(v[i])) {
            out.push_back(v[i]);
        }
    }
    return out;
}

int main()
{
    int size, minlen;
    string w;
    vector<string> v, out;
    cin >> size >> minlen;
    for (int i = 0; i < size; ++i) {
        cin >> w;
        v.push_back(w);
    }
    out = PalindromFilter(v, minlen);
    for (int i = 0; i < out.size(); ++i) cout << out[i] << endl;
    return 0;
}
