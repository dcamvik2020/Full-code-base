#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N;
    cin >> N;

    string word;
    set<string> different_words;

    for (; N; --N) {
        cin >> word;
        different_words.insert(word);
    }

    cout << different_words.size() << endl;
    return 0;
}
