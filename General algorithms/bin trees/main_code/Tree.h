#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <iostream>

#include <climits>

/// Main idea : 
/// left_child_key < key <= right_child_key

class BinTree {
private:
  typedef struct Node {
    int key;
    struct Node * left;
    struct Node * right;
	struct Node * parent;
    Node (int x = 0, Node * parent_ = nullptr) : key(x),
        left(nullptr), right(nullptr), parent(parent_) {}
	~Node () {
      delete left;
	  delete right;
    }
  } Node;

  Node * head;
  unsigned cnt_elems;
  
  Node * goToX(int x) const;

  const Node * min (const Node * node) const;
  const Node * max (const Node * node) const;
  
  const Node * next (const Node * node) const;
  const Node * prev (const Node * node) const;
  
  void print(const Node * node) const;
  void printLikeTree(const Node * node, int level) const;
  unsigned height (const Node * node) const;

  void AVLBalance (); /// TODO
  void copy (const Node * from, Node ** to);
  static bool equal (const Node * lhs, const Node * rhs);

public:
  BinTree() : head(nullptr), cnt_elems(0) {}
  BinTree(const BinTree & rhs) {
    cnt_elems = rhs.getCntElems();
	copy (rhs.head, &head);
  }
  
  bool empty() const {return cnt_elems == 0;}
  unsigned getHeight () const {return height(head);}
  unsigned getCntElems () const {return cnt_elems;}

  void insert (int x);
  void erase (int x);
  bool find (int x) const;
  
  void print () const;
  void printLikeTree () const;
  
  int min () const;
  int max () const;

  int next (int x) const;
  int prev (int x) const;

  BinTree & operator = (const BinTree & rhs)
  {
    cnt_elems = rhs.getCntElems();
	copy (rhs.head, &head);
	return *this;
  }
  friend bool operator == (const BinTree & lhs, const BinTree & rhs);
  friend bool operator != (const BinTree & lhs, const BinTree & rhs);

  ~BinTree() {
    delete head;
  }
};

#endif  /// BIN_TREE_H
