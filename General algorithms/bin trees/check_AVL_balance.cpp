/// Have : array (0 <--> stop) ---> tree
/// Know : AVL-balanced tree  <----> FOR EACH node
///        height of subtrees differ not more than by 1
/// Need : check if the tree is AVL-balanced

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



unsigned height (const Node * head);
std::string check_AVL_tree(Node * head);
void insert (Node ** head, int x);


int main ()
{
  int x;
  Node * head = nullptr;
  while (std::cin >> x && x != 0)
  {
    insert(&head, x);
  }
  std::cout << check_AVL_tree(head) << "\n";
  delete head;
  return 0;
}


std::string check_AVL_tree(Node * head)
{
  if (head == nullptr) return "YES";
  
  std::string left_AVL = check_AVL_tree(head -> left);
  if (left_AVL == "NO") return "NO";
  std::string right_AVL = check_AVL_tree(head -> right);
  if (right_AVL == "NO") return "NO";

  unsigned left_height = height(head -> left);
  unsigned right_height = height(head -> right);
  unsigned min_h = std::min (left_height, right_height);
  unsigned max_h = std::max (left_height, right_height);

  if ( max_h - min_h > 1 ) return "NO";
  return "YES";
}


void insert (Node ** head, int x)
{
  if (*head == nullptr)
  {
    *head = new Node(x);
    return;
  }

  Node * tmp = *head;
  while (tmp)
  {
    if (tmp -> key == x)
      return;
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



unsigned height (const Node * head)
{
  if (head == nullptr)
    return 0;
  unsigned left_height = height(head->left);
  unsigned right_height = height(head->right);
  return 1 + std::max(left_height, right_height);
}

