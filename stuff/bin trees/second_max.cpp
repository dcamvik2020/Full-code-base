/// Have : array --> bin search tree
/// Need : build tree, find second max

/// Idea : max     <---> rightest element
///        2nd max <---> prev for rightest element


#include <iostream>
#include <climits>

typedef struct Node {
  int key;
  Node * left;
  Node * right;
  Node (int x) : key(x), left(nullptr), right(nullptr) {}
  ~Node() {
	delete left;
    //std::cout << "delete element " << key << "\n";
    delete right;
  }
} Node;


int secondMax (Node * head);

/// returns element's height = dist (head, element) inclusively
void insert (Node ** head, int x);



int main ()
{
  int x;
  Node * head = nullptr;
  while (std::cin >> x && x != 0)
    insert(&head, x);

  std::cout << secondMax(head) << "\n";
  delete head;
  return 0;
}


int secondMax (Node * head)
{
  if (head == nullptr) return INT_MIN;
  
  if (head -> right == nullptr)
  {
    if (head -> left == nullptr) return INT_MIN;
	head = head -> left;
	while (head -> right)
	  head = head -> right;
    return head -> key;
  }
 
  while (head -> right -> right)
    head = head -> right;

  if (head -> right -> left == nullptr)
    return head -> key;

  head = head -> right -> left;
  while (head -> right)
    head = head -> right;
 
  return head -> key;  
}


void insert (Node ** head, int x)
{
  //Node * new_node = new Node(x);
  if (*head == nullptr)
  {
    *head = new Node(x);
    return;
  }

  Node * tmp = *head;
  while (tmp)
  {
    if (tmp -> key == x) /// if we create new Node(x) earlier and 
      return;            /// return here ---> memory loss

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
}

