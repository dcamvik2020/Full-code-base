#include <iostream>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& s) {
    map<char, int> letters_in_the_word;
    for (auto c : s) {
        ++letters_in_the_word[c];
    }
    return letters_in_the_word;
}

int main()
{
    int N;
    string a, b;
    cin >> N;

    for (; N; --N) {
        cin >> a >> b;
        if (BuildCharCounters(a) == BuildCharCounters(b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
