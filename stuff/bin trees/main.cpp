#include <iostream>

#include <climits>

class BinTree {
private:
  typedef struct Node {
    int key;
    struct Node * left;
    struct Node * right;
    Node (int x) : key(x), left(nullptr), right(nullptr) {}
	~Node () {
      delete left;
	  delete right;
    }
  } Node;

  Node * goToX(int x)
  {
    Node * tmp = head;
	while (tmp)
	{
      if (tmp -> key == x)
	    return tmp;

	  if (tmp -> key <= x)
	    tmp = tmp -> right;
      else
	    tmp = tmp -> left;
	}
	return tmp;
  }

  Node * next (Node * node) /// TODO
  {
    if (node -> right == nullptr)
	  return nullptr;
    
	node = node -> right;
	while (node -> left)
      node = node -> left;
	
	return node;
  }

  Node * prev (Node * node) /// TODO
  {
    if (node -> left == nullptr)
	  return nullptr;
    
	node = node -> left;
	while (node -> right)
      node = node -> right;
	
	return node;
  }

private:
  Node * head;
  unsigned cntElems;
  void balance () const;

public:
  BinTree() : head(nullptr), cntElems(0) {}
  BinTree(const BinTree & rhs) {
    head = nullptr;
	if (rhs.empty() == false)
	{
      ///copyTree;
	}
  }
  
  bool empty() const {return cntElems == 0;}

  unsigned getHeight () const;

  void insert (int x)
  {
	cntElems++;
    if (head == nullptr)
	{
	  head = new Node(x);
	  return;
	}

	Node * tmp = head;
	while (tmp)
	{
	  if (tmp -> key <= x)
	  {
	    if (tmp -> right == nullptr)
		{
		  tmp -> right = new Node(x);
		  break;
		}
		else
		  tmp = tmp -> right;
	  }
	  else
	  {
	    if (tmp -> left == nullptr)
		{
		  tmp -> left = new Node(x);
		  break;
		}
		else
		  tmp = tmp -> left;
	  }
	}
  }
  

  void erase (int x) /// TODO
  {
    if (x == head
    Node * tmp = head;
    while (tmp)
	{
      if (tmp ->
	  if (tmp -> key < x)
	    tmp = tmp -> right;
	  else
	    tmp = tmp -> left;
	}
    
	if (tmp == nullptr)
	  return;
    
    Node * next_elem = next(tmp);
    if (next_elem == nullptr) {}

    tmp -> right = nullptr;
	delete tmp;
  }


  bool find (int x)
  {
    Node * tmp = head;
	while (tmp)
	{
      if (tmp -> key == x)
	    return true;
	  if (tmp -> key < x)
	    tmp = tmp -> right;
	  else
	    tmp = tmp -> left;
	}
    return false;
  }

  void print () const; /// TODO

  int next (int x) const 
  {
    Node * ptrX = goToX(X);
	Node * next_elem = next(tmp);
    if (next_elem)
	  return next_elem -> key;
	return INT_MAX;
  }

  int prev (int x) const
  {
    Node * prev_elem = prev(tmp);
    if (prev_elem)
	  return prev_elem -> key;
	return INT_MIN;
  }

  ~BinTree() {
    delete head;
  }
};

int main () {
  BinTree tree;
  tree.insert(5);
  std::cout << std::boolalpha << tree.find(5) << "\n";
  return 0;
}
