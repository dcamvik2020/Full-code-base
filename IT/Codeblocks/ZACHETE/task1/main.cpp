#include <iostream>

using namespace std;

class Parent {
protected:
    int a;
public:
    Parent(int a) : a(a) {
        cout << "Parent constructor : int a = " << a << endl;
    }
    virtual ~Parent() {
        cout << "Parent destructor : int a = " << a << endl;
    }
};

class Child : public Parent {
public:
    Child(int a) : Parent(a) {
        Parent(a+1);
        cout << "Child constructor : int a = " << a << endl;
    }
    ~Child() {
        cout << "Child destructor : int a = " << a << endl;
    }
};

int main()
{
    Child *a = new Child(5);
    delete a;

    cout << endl;

    Parent *b = new Child(5);
    b->~Parent();
    //delete b;
    return 0;
}
