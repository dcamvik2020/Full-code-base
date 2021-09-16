/// Have : N people, N-1 lines in format "child parent"
/// Need : for every person count children

/// Example :               Output :
/// 9                       Alexander_I 0
/// Alexei Peter_I          Alexei 1
/// Anna Peter_I            Anna 4
/// Elizabeth Peter_I       Elizabeth 0
/// Peter_II Alexei         Nicholaus_I 0
/// Peter_III Anna          Paul_I 2
/// Paul_I Peter_III        Peter_I 8
/// Alexander_I Paul_I      Peter_II 0
/// Nicholaus_I Paul_I      Peter_III 3

/// TODO : RE on tests

#include <iostream>

#include <map>
#include <vector>
class FamilyTree {
private:
  
  typedef struct Node {
    std::string name;
    unsigned descendants;
	Node * parent;
    std::vector<Node *> children;
  
    Node (const std::string & name_, Node * parent_ = nullptr) 
	    : name(name_), descendants(0), parent(parent_) {}
    ~Node() {
      for (Node * child : children)
        delete child;
    } 
  } Node;


  Node * position (Node * node, const std::string & person)
  {
    if (node -> name == person)
	  return node;
    for (Node * child : node -> children)
	{
      Node * res = position(child, person);
	  if (res)
	    return res;
    }
    return nullptr;
  }

  Node * head;
  std::map<std::string, int> person_cnt_descendants;

public:
  FamilyTree() : head(nullptr) {}
  ~FamilyTree() {delete head;}

  void insert (const std::string & parent, const std::string & person)
  {
	person_cnt_descendants[person] += 0;

	if (head == nullptr)
    {
      head = new Node(parent);
	  head->descendants++;
	  head->children.push_back(new Node(person, head));
	  person_cnt_descendants[parent]++;
      return;
    }

    Node * ptr_parent = position(head, parent);
	ptr_parent->children.push_back(new Node(person, ptr_parent));
	while (ptr_parent)
	{
      ptr_parent->descendants++;
	  person_cnt_descendants[ptr_parent->name] += 1;
	  ptr_parent = ptr_parent->parent;
	}
  }

  void print_descendants_number () const
  {
    //std::cout << "People saved : " 
	//          << person_cnt_descendants.size() << "\n";
	for (const auto & p : person_cnt_descendants)
	{
      std::cout << p.first << " " << p.second << "\n";
	}
  }
};

int main ()
{
  int N;
  std::cin >> N;

  FamilyTree tree;
  for (int i = 0; i < N - 1; ++i)
  {
    std::string child, parent;
    std::cin >> child >> parent;
    tree.insert(parent, child);
  }
  tree.print_descendants_number();
  return 0;
}
