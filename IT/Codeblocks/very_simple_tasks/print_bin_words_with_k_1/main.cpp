#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

void print_bin_iter(int n, int k) {
    std::string s(n, '0');
    for (int i = 0; i < (1 << n); ++i) {
        int l = 0; // '1' in s
        for (int j = 0; s[j]; ++j) {
            if (s[j] == '1') ++l;
        }
        if (l == k) cout << s << endl;

        l = 0;
        for (int j = n - 1; s[j] == '1'; --j, ++l);
        for (int j = n - 1 - l; s[j]; s[j] = '0', j++);
        s[n - 1 - l] = '1';
    }
}



///          not
///          ended
///          program
///
///          modifications !!!


void print_bin_rec(int n, int k, const std::string & last) {
    std::string s(n, '0');
    if (last != "" && l == k) cout << last << endl;
    for (int i = 0; last[i]; s[i] = last[i] ,i++);

    int k = 0; // '1' in the end
    for (int j = n - 1; s[j] == '1'; --j, ++k);

    if (k != n) {
        for (int j = n - 1 - k; s[j]; s[j] = '0', j++);
        s[n - 1 - k] = '1';
        print_bin_rec(n, s);
    }
}

int main() {

    int n, k;
    cin >> n >> k;

    print_bin_iter (n, k);
    //print_bin_rec (n, "");


    // your code goes here
    return 0;
}
