#include<iostream>

enum class Color {
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
  unsigned black_height;

  void balance ();
  void count_black_height ();

public:
  RBTree() : head(nullptr), black_height(0) {}

  void insert (int x);
  void delete (int x);
  void print () const;
  unsigned getBlackHeight () const {return black_height;}

  ~RBTree() {delete head;}
}
