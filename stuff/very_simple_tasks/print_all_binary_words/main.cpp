#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

void print_bin_iter(int n) {
    std::string s(n, '0');
    for (int i = 0; i < (1 << n); ++i) {
        cout << s << endl;

        int k = 0; // '1' in the end
        for (int j = n - 1; s[j] == '1'; --j, ++k);
        for (int j = n - 1 - k; s[j]; s[j] = '0', j++);
        s[n - 1 - k] = '1';
    }
}

void print_bin_rec(int n, const std::string & last) {
    std::string s(n, '0');
    if (last != "") cout << last << endl;
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

    int n;
    cin >> n;

    //print_bin_iter (n);
    print_bin_rec (n, "");


    // your code goes here
    return 0;
}
