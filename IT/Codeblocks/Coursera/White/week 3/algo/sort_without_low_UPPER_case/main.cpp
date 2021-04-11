#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) {
        return s1.size() < s2.size();
    }

    for (int i = 0; i < s1.size(); ++i) {
        if (tolower(s1[i]) != tolower(s2[i])) {
            return tolower(s1[i]) < tolower(s2[i]);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    vector<string> v(N);
    for (auto& i : v) {
        cin >> i;
    }

    sort(begin(v), end(v), cmp);

    for (auto& i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
