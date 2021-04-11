#include <iostream>
#include <vector>
#include <map>
#include <set>
//#include <algorithm>

using namespace std;

/// the order is important --> call it 2 times
bool are_synonyms(map<string, set<string>>& words_to_synonyms, const string& word1, const string& word2) {
    ///set<string> tmp;
    if (words_to_synonyms.count(word1) > 0) {
        ///tmp = words_to_synonyms[word1]; --> it may be a very long time operation
        /*if (count(begin(words_to_synonyms[word1]), end(words_to_synonyms[word1]), word2)) {*/ /// It needs    <algorithm>
        if (words_to_synonyms[word1].count(word2)) {
            return true;
        }
    }
    return false;
}

int main()
{
    /// a != b
    /// (a ~ b) = there was command "ADD a b"/ "ADD b a"
    /// so, there is NO transitivity in it

    int Q;
    cin >> Q;
    map<string, set<string>> words_to_synonyms;

    for (; Q; --Q) {
        string cmd;
        cin >> cmd;

        if (cmd == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;

            /// check existance    and     do smth if this pair doesn't exist
            /*if (!are_synonyms(words_to_synonyms, word1, word2) && */  /// IT IS A VERY LONG TIME OPERATION
            /*    !are_synonyms(words_to_synonyms, word2, word1)) {(*/  /// WE HAVE SET --> IT MAKE ALL CHECKS!!
                words_to_synonyms[word1].insert(word2);
                words_to_synonyms[word2].insert(word1);
            //}

        } else if (cmd == "COUNT") {
            string word;
            cin >> word;
            if (words_to_synonyms.count(word) == 0) {  /// it is NOT a
                cout << 0 << endl;                     /// too long time
            } else {                                   /// operation
                //cout << "size of map: " << words_to_synonyms.size() << "   size of ... : " << words_to_synonyms[word].size() << "      size of map: " << words_to_synonyms.size() << endl;
                cout << words_to_synonyms[word].size() << endl;
            }
        } else if (cmd == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            /// we have pushed already    word1 to word2    AND     word2 to word1
            /// if they are synonyms ---> need only one check
            if (/*are_synonyms(words_to_synonyms, word1, word2) ||*/
                are_synonyms(words_to_synonyms, word2, word1)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

    }

    return 0;
}
