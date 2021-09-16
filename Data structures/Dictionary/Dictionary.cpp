
#include "Dictionary.h"

unsigned Node::pos_char (char c) {
    for (unsigned i = 0; i < children.size(); ++i) {
        if (children[i]->c == c) {
            return i;
        }
    }
    return -1;
}

unsigned Node::insert_child (char c) {
    Node * tmp;
    unsigned index;

    children.resize(children.size() + 1); // last Node *  = NULL (default)
    children[children.size() - 1] = new Node(c);

    for (index = children.size() - 1; index > 0; --index) {
        if (children[index - 1]->c > children[index]->c) {
            tmp                  = children[index - 1];
            children[index - 1]  = children[index];
            children[index]      = tmp;
        } else {
            break;
        }
    }
    return index;
}



bool check_word (const std::string & word) {
    /// Don't remember empty words
    if (word == "") {
        cerr << "We can't remember empty words!" << endl;
        return false;
    }

    /// check word for wrong symbols
    for (unsigned i = 0; word[i]; ++i) {
        if (!('A' <= word[i] && word[i] <= 'Z') &&
            !('a' <= word[i] && word[i] <= 'z')) {
            /*cout << "i: " << i << "   word[i] = "
                 << word[i] << endl;
            cout << "           1: " << ('A' <= word[i])
                 << "\n           2: " << (word[i] <= 'Z')
                 << "\n           3: " << ('a' <= word[i])
                 << "\n           4: " << (word[i] <= 'z');*/
            cerr << "\nWrong format of word!" << endl;
            return false;
        }
    }
    return true;
}

/// "follow" <--> like in DKA in TRYAP  =)
unsigned Dictionary::follow_word (Node * & start, const std::string & word) {
    
    unsigned i, position;
    for (i = 0; word[i]; ++i) {
        position = start -> pos_char(word[i]);

        /// found the last letter that already exists
        if (position == (unsigned) -1) {
            break;
        }

        /// else find further
        start = start -> children[position];
    }

    return i;

}

bool Dictionary::exists (const std::string & word) {
    Node * symbol = head;
    unsigned i = follow_word(symbol, word);
    
    if (i < word.size() || symbol -> end == false) {
        return false;
    }
    return true;
}

void Dictionary::add_word (const std::string & word) {
    
    if (check_word(word) == false) {
        return;
    }

    /// Check emptiness of dictionary
    if (head == NULL) {
        head = new Node();
    }

    /// Follow by first letters of the word
    Node * symbol = head;
    unsigned i = follow_word(symbol, word);

    /// Check existance of the word
    if (i == word.size()) {
        if (symbol->end == true) {
            cerr << "The word already exists!" << endl;
        } else {
            cerr << "The word is a part of another word!" << endl;
        }
        return;
    }

    /// Write new word in dictionary from word[i]
    unsigned position;
    for (; word[i]; ++i) {
        /// Node.children --> private --> Vector<>.insert doesn't
        /// work as well : it just pushes, not inserts in sorted order
        //position = symbol->children.insert(tmp);
        
        /// local solution for insertion by pointer  (Node *)
        position = symbol -> insert_child(word[i]);

        symbol = symbol->children[position];
    }

    /// mark the last char as "end"
    symbol->end = true;
}

void Dictionary::remove_word (const std::string& word) {
    
    Node * symbol;
    unsigned i, position;
    
    /// find the last "end" symbol && check existance
    for (i = 0, symbol = head; word[i]; ++i) {
        position = symbol -> pos_char(word[i]);
        if (position == (unsigned) -1) {
            cerr << "The word doesn't exist in dictionary!" << endl;
            return;
        }
        symbol = symbol -> children[position];
    }

    /// check if the last in word[] is the "end"-symbol
    if (symbol -> end == false) {
        cout << "The word doesn't exist in dictionary!" << endl;
        return;
    }

    /// just mark the word as "not end"
    symbol -> end = false;

}

void print(const Dictionary& dict) {
    Node * head = dict.head;
    if (head->children.size() == 0) {
        cout << "Empty dictionary" << endl;
        return;
    }

    unsigned size = head -> children.size();
    for (unsigned i = 0; i < size; ++i) {
        std::string buf(BUF_SIZE, '\0');
        //cout << head->children[i]->c;
        recursive_print(head->children[i], buf, 0);
    }
}

void recursive_print(Node * start, std::string& buf, unsigned level) {
    
    buf[level] = start->c;
    if (start->end == true) {
        cout << buf << endl;
        //cout << endl;
        //return;
    }

    for (unsigned i = 0; i < start->children.size(); ++i) {
        //cout << start->children[i]->c;
        recursive_print(start->children[i], buf, level + 1);
    }
}



