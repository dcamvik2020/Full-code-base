#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

class Node {
private:
    int x;
    Node * left;
    Node * right;
    Node * parent;

    Node (int x = 0) : x(x), left(NULL), right(NULL), parent(NULL) {
    }
    ~Node() {
        delete left;
        delete right;
    }

    const Node & operator = (const Node & obj) {
        x = obj.x;
        left = obj.left;
        right = obj.right;
        /// parent --> don't think about it
        return *this;
    }
    friend bool operator < (Node a, Node b) {
        return a.x < b.x;
    }

    friend class BinTree;
    friend void recursive_print (Node * start);
};


class BinTree {
private:
    Node * head;

    Node * find (int x) {
        Node * start;
        for (start = head; (start != NULL) && (x != start -> x); ) {
            if (x < start -> x) {
                start = start -> left;
            } else {
                start = start -> right;
            }
        }
        return start;
    }

    Node * next (Node * start) {
        if (start == NULL) {
            return NULL;
        }

        if (start -> right) {
            return min(start -> right);
        }
        
        Node * parent = start -> parent;
        while ((parent != NULL) && (start == parent -> right)) {
            start = parent;
            parent = parent -> parent;
        }
        
        return parent;
    }

    Node * prev (Node * start) {
        if (start == NULL) {
            return NULL;
        }

        if (start -> left) {
            return max(start -> left);
        }

        Node * parent = start -> parent;
        while ((parent != NULL) && (start == parent -> left)) {
            start = parent;
            parent = parent -> parent;
        }

        return parent;
    }

public:
    BinTree() : head(NULL) {
    }

    bool exists (int x) {
        Node * element = find(x);
        if (element == NULL) {
            return false;
        }
        return true;
    }

    void add (int x) {
        Node * parent = NULL;
        Node * element = head;
        
        while (element != NULL) {
            parent = element;
            if (x < element -> x) {
                element = element -> left;
            } else {
                element = element -> right;
            }
        }

        element = new Node(x);
        element -> parent = parent;
        if (parent == NULL) {
            head = element;
        } else {
            if (x < parent -> x) {
                parent -> left = element;
            } else {
                parent -> right = element;
            }
        }
    }

    void erase(int x) {
        Node * a = find(x);
        if (a == NULL) {
            cerr << "No match" << endl;
            return;
        }

        /// 0 children
        if ((a -> left == NULL) && (a -> right == NULL) ) {
            if (a -> parent) {
                if (a == a -> parent -> left) {
                    a -> parent -> left = NULL;
                } else {
                    a -> parent -> right = NULL;
                }
            }
            delete a;
            return;
        }
        
        /// 1 children
        if (a -> left == NULL || a -> right == NULL) {
            Node * b = (a -> left) ? (a -> left) : (a -> right);
            if (a -> parent) {
                if (a == a -> parent -> left) {
                    a -> parent -> left = b;
                } else {
                    a -> parent -> right = b;
                }
            }
            b -> parent = a -> parent;
            ((a -> left) ? (a -> left) : (a -> right)) = NULL;
            delete a;
            return;
        }

        /// 2 children
        Node * b = next(a); /// b -> parent != NULL 100%
        if (b != a -> right) {                 /// b->right may
            b -> parent -> left = b -> right;  /// be not NULL
        } else {                               /// => remember it
            a -> right = b -> right;
        }
        a -> x = b -> x;
        b -> right = NULL;
        delete b;
        
    }

    Node * min (Node * start) {
        while (start && start -> left) {
            start = start -> left;
        }
        return start;
    }

    Node * max (Node * start) {
        while (start && start -> right) {
            start = start -> right;
        }
        return start;
    }


    friend void print(const BinTree & tree);
    friend void recursive_print(Node * start);

    ~BinTree() {
        delete head;
    }
};


void print(const BinTree & tree) {
    if (tree.head == NULL) {
        cout << "Tree is empty!" << endl;
        return;
    }

    recursive_print(tree.head);
}

void recursive_print(Node * start) {
    if (start == NULL) {
        return;
    }
    cout << "item : " << start -> x;
    if (start -> left) {
        cout << "      left : " << start -> left -> x ;
    }
    if (start -> right) {
        cout << "      right : " << start -> right -> x ;
    }
    cout << endl;
    recursive_print(start->left);
    recursive_print(start->right);
}



void Usage() {
    cout << endl;
    cout << "Binary tree's usage:" << endl << endl;
    cout << "add (number)          Add number to the tree." << endl;
    cout << "erase (number)        Delete number from the tree, if it exists." << endl;
    cout << "find (number)         Check number's existance in the tree." << endl;
    cout << "print                 Print the tree." << endl;
    cout << "man / help            View binary tree's usage." << endl;
    cout << "stop / exit           Stop running program." << endl;
    cout << endl;
}

int main() {
    Usage();
    int number;
    BinTree tree;
    std::string cmd;
    
    while (1) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> number;
            tree.add(number);
        } else if (cmd == "erase") {
            cin >> number;
            tree.erase(number);
        } else if (cmd == "find") {
            cin >> number;
            bool element = tree.exists(number);
            if (element) {
                cout << "Element exists" << endl;
            } else {
                cout << "No match for element" << endl;
            }
        } else if (cmd == "print") {
            print(tree);
        } else if (cmd == "man" || cmd == "help") {
            Usage();
        } else if (cmd == "stop" || cmd == "exit") {
            break;
        } else {
            cout << "Unknown command!" << endl;
        }
    }
    
    return 0;
}
