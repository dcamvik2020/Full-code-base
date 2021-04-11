#include <iostream>
#include <string>

#include "Vector.h"

#define BUF_SIZE 100

class Dictionary;
/// proprietary class of class Dictionary
class Node {
private:
    char c;
    bool end;
    Vector<Node*> children;

    Node (char c = '\0') : c(c), end(false), children(0) {}

    unsigned pos_char (char c);
    unsigned insert_child (char c);

    ~Node () {
	unsigned size = children.size();
    	for (unsigned i = 0; i < size; ++i) {
            delete children[i];
	}	
    }

    friend bool operator < (Node a, Node b) {return a.c < b.c;}

    /// only Dictionary-class may use this class's objects
    friend class Dictionary;
    friend void print(const Dictionary& dict);
    friend void recursive_print(Node * start, std::string& buf, unsigned level);
};


bool check_word (const std::string & word);

class Dictionary {
private:
    Node * head;

public:
    Dictionary () : head(NULL) {}

    /// "follow" <--> like in DKA in TRYAP  =)
    unsigned follow_word (Node * & start, const std::string & word); 
    bool exists (const std::string & word);

    void add_word (const std::string & word);
    void remove_word (const std::string& word);
    friend void print(const Dictionary& dict);
    friend void recursive_print(Node * start, std::string& buf, unsigned level); 


    ~Dictionary () {
        delete head;
    }
};


