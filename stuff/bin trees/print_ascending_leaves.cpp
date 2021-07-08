/// Have : array --> tree
/// Need : tree --> print ascending array of leaves

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


void insert (Node ** head, int x);
void print(const Node * head);
void print_leaves(const Node * head);


int main ()
{
  int x; 
  Node * head = nullptr;
  while (std::cin >> x && x != 0)
  {
    insert(&head, x);
  }
  print_leaves(head);
  std::cout << "\n";
  delete head;
  return 0;
}



void print(const Node * head)
{
  if (head == nullptr) return;
  if (head -> left) 
  {
    print(head->left);
    std::cout << " ";
  }
  std::cout << head->key;
  if (head -> right)
  {
    std::cout << " ";
    print(head->right);
  }
}


void print_leaves(const Node * head)
{
  if (head == nullptr) return;

  print_leaves(head->left);
  
  if (head -> left == nullptr && head -> right == nullptr)
    std::cout << head->key << " ";
  
  print_leaves(head->right);
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

