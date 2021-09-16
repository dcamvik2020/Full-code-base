
#include "Dictionary.h"

void Usage() {
    cout << endl;
    cout << "Dictionary :" << endl;
    cout << "    add               Add a word to dictionary." << endl;
    cout << "    delete            Delete a word from dictionary." << endl;
    cout << "    find              Find a word in dictionary." << endl;
    cout << "    print             Print all thr words from dictionary." << endl;
    cout << "    man / help        See usage of dictionary." << endl;
    cout << "    .                 Stop program." << endl;
    cout << endl;
}

int main() {
    
    Usage();

    Dictionary dict;
    std::string cmd, s;
    while (1) {
        
        cout << " >>> ";
        cin >> cmd;

        if (cmd == "add") {
            cin >> s;
            dict.add_word(s);
        } else if (cmd == "delete") {
            cin >> s;
            dict.remove_word(s);
        } else if (cmd == "find") {
            cin >> s;
            bool exists = dict.exists(s);
            if (exists) {
                cout << "Exists" << endl;
            } else {
                cout << "No match" << endl;
            }
        } else if (cmd == "man" || cmd == "help") {
            Usage();
        } else if (cmd == "print") {
            print(dict);
            cout << endl;
        } else if (cmd == ".") {
            cout << endl;
            break;
        }
    }

    return 0;
}
