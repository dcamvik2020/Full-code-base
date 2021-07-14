#include<iostream>

enum class Color {  // TODO TODO TODO : check enum-theory
  RED = 0,
  BLACK = 1;
};

class RBTree {
private:
  typedef struct Node {
    int val;
	bool color; // 0 = red, 1 = black
    Node * left;
	Node * right;
    Node (int x) : val(x), color(Color::BLACK),
	              left(nullptr), right(nullptr) {}
    ~Node()
	{
      delete left;
	  delete right;
	}
  } Node;

  Node * head;

  void balance()

public:
  RBTree() {}

  insert
  delete
  print

  ~RBTree() {delete head;}
}
