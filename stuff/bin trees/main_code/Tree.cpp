#include "Tree.h"

/// used for min, max of the tree
BinTree::Node * BinTree::goToX(int x) const
{
  Node * tmp;
  for (tmp = head; tmp && tmp -> key != x; )
  {
    if (tmp -> key < x)
      tmp = tmp -> right;
    else
	{
      /// tmp -> key >= x
	  if (tmp -> left &&
	      tmp -> left -> key < x &&
		  tmp -> left -> right == nullptr)
	    break; /// return first key > x if there's no x
      tmp = tmp -> left;
    }
  }
  return tmp; /// nullptr <--> all keys < x
}


const BinTree::Node * BinTree::min (const BinTree::Node * node) const
{
  while (node -> left)
    node = node -> left; 
  return node;
}


const BinTree::Node * BinTree::max (const BinTree::Node * node) const
{
  while (node -> right)
    node = node -> right;
  return node;
}


const BinTree::Node * BinTree::next (const BinTree::Node * node) const
{
  if (node == nullptr)
    return nullptr;
  if (node -> right)
    return min(node->right);

  /// find parent
  while (node -> parent && node == node -> parent -> right)
    node = node -> parent;
  return node->parent;  
}


const BinTree::Node * BinTree::prev (const BinTree::Node * node) const
{
  if (node == nullptr)
    return nullptr;
  if (node -> left)
    return max(node->left);
  
  /// find parent
  while (node -> parent && node == node -> parent -> left)
    node = node -> parent;
  return node -> parent;
}


void BinTree::AVLBalance () {} /// TODO


void BinTree::copy (const BinTree::Node * from, BinTree::Node ** to)
{
  if (from == nullptr)
  {
    *to = nullptr;
	return;
  }
  *to = new Node(from -> key, from -> parent);
  copy (from -> left, &((*to) -> left));
  copy (from -> right, &((*to) -> right));
}


bool BinTree::equal (const BinTree::Node * lhs, const BinTree::Node * rhs)
{
  if (lhs == nullptr && rhs == nullptr)
    return true;
  if (lhs == nullptr || rhs == nullptr ||
	  lhs->key != rhs->key)
    return false;
  return equal(lhs->left, rhs->left) &&
         equal(lhs->right, rhs->right);
}


// height = # of levels (if only head exists --> height = 1)
unsigned BinTree::height (const BinTree::Node * node) const
{
  if (node == nullptr) return 0;
  return std::max(height(node->left), height(node->right)) + 1;
}



void BinTree::insert (int x)
{
  cnt_elems++;
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
        tmp -> right = new Node(x, tmp);
        break;
      }
      else
        tmp = tmp -> right;
    }
    else
    {
      if (tmp -> left == nullptr)
      {
        tmp -> left = new Node(x, tmp);
        break;
      }
      else
        tmp = tmp -> left;
    }
  }
}



void BinTree::erase (int x)
{
  Node * cur = head;
  Node * prev = nullptr;
  bool direction; /// 0 - left, 1 - right
  while (cur && cur -> key != x)
  {
    prev = cur;
    if (cur -> key < x)
	{
      cur = cur -> right;
	  direction = 1;
	}
	else
	{
      cur = cur -> left;
	  direction = 0;
	}
  }

  /// x doesn't exists
  if (cur == nullptr)
    return;
 
  cnt_elems--;

  /// x doesn't have children
  if (cur -> left == nullptr && cur -> right == nullptr)
  {
	if (cur != head) /// prev != nullptr
	{
      if (direction == 1) 
	    prev -> right = nullptr;
	  else
	    prev -> left = nullptr;
	}
	delete cur;
	if (cur == head)  /// look at print functions, we need
	  head = nullptr; /// the head nullptr if tree is empty
	return;
  }

  /// x has only 1 child
  Node * single_child = nullptr;
  if (cur -> left && cur -> right == nullptr)
    single_child = cur -> left;
  else if (cur -> left == nullptr && cur -> right)
    single_child = cur -> right;
  
  if (single_child)
  {
    cur -> key = single_child -> key;
	cur -> left = single_child -> left;
	cur -> right = single_child -> right;
	single_child -> left = single_child -> right = nullptr;
	delete single_child;
	return;
  }

  /// x has both children
  /// 1 case : right child doesn't have its own left
  if (cur -> right -> left == nullptr)
  {
    Node * to_remove = cur -> right;
	cur -> key = cur -> right -> key;
	cur -> right = cur -> right -> right;
	to_remove -> right = nullptr;
	delete to_remove;
  }
  else /// 2 case : right child has both its own children
  {
    /// prev1, cur1 : pointers in right subtree of cur
	Node * prev1 = cur;
	Node * cur1 = cur -> right;
	while (cur1 -> left)
	{
	  prev1 = cur1;
	  cur1 = cur1 -> left;
	}
	/// cur1 has only right child
	cur -> key = cur1 -> key;
	prev1 -> left = cur1 -> right;
	cur1 -> right = nullptr;
	delete cur1;
  }
}



bool BinTree::find (int x) const
{
  for (BinTree::Node * tmp = head; tmp; )
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


void BinTree::print(const BinTree::Node * node) const
{
  if (node)
  {
    print(node->left);
	if (node->left) std::cout << " ";
    std::cout << (node -> key);
	if (node->right) std::cout << " ";
    print(node->right);
  }
}

void BinTree::print () const
{
  std::cout << "--------------------------------\n";
  std::cout << "Array-like form of presentation:\n";
  std::cout << "We have " << cnt_elems << " elements in the tree\n";
  std::cout << "Tree's height is " << getHeight() << "\n";
  print(head);
  std::cout << "--------------------------------\n";
}



void BinTree::printLikeTree (const Node * node, int level) const
{
  if (node == nullptr)
    return;
  const char * tab = "   ";
  for (int i = 0; i < level; ++i)
    std::cout << tab;
  std::cout << (node->key) << "\n";
  if (node->left)
    printLikeTree(node->left, level + 1);
  if (node->right)
    printLikeTree(node->right, level + 1);
}



void BinTree::printLikeTree () const
{
  std::cout << "--------------------------------\n";
  std::cout << "Tree-like form of presentation:\n";
  std::cout << "We have " << cnt_elems << " elements in the tree\n";
  std::cout << "Tree's height is " << getHeight() << "\n";
  printLikeTree(head, 0);
  std::cout << "--------------------------------\n";
}


int BinTree::min () const
{
  const Node * min_ptr = min(head);
  if (min_ptr == nullptr)
    return INT_MIN;
  return min_ptr -> key;
}


int BinTree::max () const
{
  const Node * max_ptr = max(head);
  if (max_ptr == nullptr)
    return INT_MAX;
  return max_ptr -> key;
}


int BinTree::next (int x) const
{
  const BinTree::Node * ptr_x = goToX(x);
  if (ptr_x && ptr_x->key != x)
    return ptr_x->key;
  const BinTree::Node * next_ptr = next(ptr_x);
  if (next_ptr == nullptr) 
    return INT_MAX;
  return next_ptr->key;
}

int BinTree::prev (int x) const
{
  const BinTree::Node * ptr_x = goToX(x);
  if (ptr_x && ptr_x->key != x)
    return ptr_x->key;
  const BinTree::Node * prev_ptr = prev(ptr_x);
  if (prev_ptr == nullptr)
    return INT_MIN;
  return prev_ptr->key;
}

bool operator == (const BinTree & lhs, const BinTree & rhs)
{
  return BinTree::equal(lhs.head, rhs.head);
}

bool operator != (const BinTree & lhs, const BinTree & rhs)
{
  return !BinTree::equal(lhs.head, rhs.head);
}
