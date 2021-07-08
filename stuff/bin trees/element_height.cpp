/// Have : array of elements --> insert to the tree
/// Know : element already exists --> don't insert it
/// Need : for every element std::cout << it's height
/// Note : element's height = dist (head, element) inclusively
/// example : 7 3 2 1 9 5 4 6 8 0 ---> 1 2 3 4 2 3 4 4 3 

#include <iostream>

typedef struct Node {
  int key;
  Node * left;
  Node * right;
  Node (int x) : key(x), left(nullptr), right(nullptr) {}
  ~Node() {
    delete left;
    delete right;
  }
} Node;

/// returns element's height = dist (head, element) inclusively
unsigned insert (Node ** head, int x);

int main ()
{
  int x;
  Node * head = nullptr;
  while (std::cin >> x && x != 0)
  {
    unsigned height = insert(&head, x);
	if (height) /// height == 0 <--> alresdy exists
	  std::cout << height << " ";
  }
  std::cout << "\n";
  delete head;
  return 0;
}


unsigned insert (Node ** head, int x)
{
  unsigned element_height = 1; /// since inclusively
  if (*head == nullptr)
  {
    *head = new Node(x);
    return element_height;
  }

  Node * tmp = *head;
  while (tmp)
  {
    if (tmp -> key == x)
      return 0;
    element_height++;
	if (tmp -> key < x)
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
  return element_height;
}
