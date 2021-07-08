/// Have : N people, N-1 lines in format "child parent"
/// Need : for every person count children

#include <iostream>

/*
#include <vector>
typedef struct Node {
  std::string name;
  unsigned descendants;
  std::vector<Node *> children;
  Node (const std::string & name_) : name(name_), descendants(0) {}
  ~Node()
  {
    for (auto & child : children)
      delete child;
  }
} Node;


Node * find (Node * head, const std::string & name);
void insert (Node * head, const std::string & parent, 
                          const std::string & child);

void print_descendants_number (Node * head);
*/


#include <map>
#include <vector>
int main ()
{
  int N;
  std::cin >> N;

  std::map<std::string, std::vector<std::string>> person_descendants;
  //Node * head;
  std::string child, parent;
  for (int i = 0; i < N - 1; ++i)
  {
    std::cin >> child >> parent;
    //insert(head, parent, child);
	person_descendants[parent].push_back(child);;
	person_descendants[child];
  }
  //print_descendants_number(head);
  
  for (auto & info : person_descendants)
    std::cout << info.first << " " << info.second << "\n";
  return 0;
}

/*
Node * find (Node * head, const std::string & name)
{
  if (head == nullptr)
    return nullptr;

  Node * ptr = head;
  if (ptr -> name == name)
    return ptr;

  if (head -> left)
    ptr = find (head -> left, name);
  if (ptr == nullptr)
    ptr = find (head -> right, name);
  
  return ptr;
}


void insert (Node ** head, const std::string & child, 
                          const std::string & parent)
{
  Node * ptr_parent = find (head, parent);
  if (ptr_parent == nullptr)
  {
    /// first pair
    *head = new Node (parent);
    ptr_parent = head;
  }

  (ptr_parent -> children).push_back(new Node (child));
}



void print_descendants_number (Node * head)
{
  if (head == nullptr)
    return;


  for (auto & child : children)
  {
    print_children_number(head -> left);
    head -> descendants += child -> descendants;
  }
  std::cout << head -> name << " " << head -> descendants << "\n";
  
  print_children_number(head -> right);
}
*/
