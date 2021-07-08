/// Have : array with integer numbers  (0 <--> finish of the array)
/// Know : x already exists --> don't add it
/// Need : build bin search tree and count it height

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
unsigned height (const Node * head);
void print(const Node * head);



int main ()
{
  int x;
  Node * head = nullptr;
  while (std::cin >> x && x != 0)
  {
    insert(&head, x);
  }
  //print(head);
  std::cout << height(head) << "\n";
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
