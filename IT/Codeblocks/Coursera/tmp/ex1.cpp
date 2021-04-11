#include <iostream>
#include <memory>
using namespace std;




class Node {
  virtual int sum () const = 0;
};




class Number : public Node {
private:
  const int & x_;
public :
  Number(const int & x) : x_(x) {
  }
  int sum () const override {
    return x_;
  }
};




class Sum : public Node {
private:
  const int & a_;
  const int & b_;
public:
  Sum(const int& a, const int& b) : a_(a), b_(b) {
  }
  int sum() const override {
    return Number(a_).sum() + Number(b_).sum();
  }
};




int main() {
  
  int a, b;
  int sum;
  
  // ...
  // operations
  // ...

  cin >> a >> b;
  cout << sum;



  
  Sum sum(a, b);
  while (cin >> a >> b)
    cout << sum.sum() << endl;
  






  /*int a0, b0;
    shared_ptr<int> a(&a0);
    shared_ptr<int> b(&b0);
    int sum;
    shared_ptr<int> sum_ptr(&sum);
     
    *sum_ptr = *a + *b;
    while (cin >> a0 >> b0) {
        cout << "a0 = " << a0 << ", b0 = " << b0 << endl;
        cout << "*a = " << *a << ", *b = " << *b << endl;
        cout << *sum_ptr << endl << endl;;
    }*/
  
  return 0;
}
