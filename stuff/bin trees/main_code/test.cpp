#include "Tree.h"

void TestInsert (BinTree & my_tree)
{
  //std::cout << "\t\tINSERT TEST\n";
  my_tree.insert(10);
  my_tree.insert(2);
  my_tree.insert(3);
  my_tree.insert(5);
  my_tree.insert(9);
  my_tree.insert(11);
  my_tree.insert(7);
  my_tree.insert(4);
  my_tree.insert(3);
  my_tree.insert(1);
  my_tree.insert(6);
  //my_tree.printLikeTree();
  //std::cout << "\n\n\n";
  std::cout << "Test Insert : OK\n";
}



void TestFindAfterInsert (BinTree & my_tree)
{
  if (my_tree.find(10) == false) {
    std::cout << "Error : 10 exists\n";
    return;
  } else if (my_tree.find(6) == false) {
    std::cout << "Error : 6 exists\n";
    return;
  } else if (my_tree.find(11) == false) {
    std::cout << "Error : 11 exists\n";
    return;
  } else if (my_tree.find(20) == true) {
    std::cout << "Error : 20 doesn't exist\n";
    return;
  } else if (my_tree.find(13) == true) {
    std::cout << "Error : 13 doesn't exist\n";
    return;
  } else if (my_tree.find(2) == false) {
    std::cout << "Error : 2 exists\n";
    return;
  } else if (my_tree.find(1) == false) {
    std::cout << "Error : 1 exists\n";
    return;
  } else if (my_tree.find(5) == false) {
    std::cout << "Error : 5 exists\n";
    return;
  } else if (my_tree.find(7) == false) {
    std::cout << "Error : 7 exists\n";
    return;
  } else if (my_tree.find(4) == false) {
    std::cout << "Error : 4 exists\n";
    return;
  }
  std::cout << "Test Find : OK\n";
}



void TestCopy (BinTree & my_tree)
{
  BinTree new_tree(my_tree);
  if (new_tree != my_tree) {
    std::cout << "Error : copy of tree != tree\n";
    return;
  }

  BinTree new_tree_2 = my_tree;
  if (new_tree_2 != my_tree) {
    std::cout << "Error : copy_2 of tree != tree\n";
    return;
  }

  new_tree.insert(4);
  if (new_tree == new_tree_2) {
    std::cout << "Error : modified copy == old copy\n";
    return;
  }
  std::cout << "Test Copy : OK\n";
}



/*
--------------------------------
Tree-like form of presentation:
We have 11 elements in the tree
Tree's height is 7
10
   2
      1
      3
         5
            4
               3
            9
               7
                  6
   11
--------------------------------
*/
void TestPrevNext(BinTree & my_tree)
{
  /// next section
  if (my_tree.next(11) != INT_MAX)
  {
    std::cout << "Test Prev Next Error : next for 11 is INT_MAX\n";
	std::cout << "\tbut we have : next = " << my_tree.next(11) << "\n";
    my_tree.printLikeTree();
	return;
  }
  if (my_tree.next(2) != 3)
  {
    std::cout << "Test Prev Next Error : next for 2 is 3\n";
	std::cout << "\tbut we have : next = " << my_tree.next(2) << "\n";
    my_tree.printLikeTree();
	return;
  }
  if (my_tree.next(5) != 6)
  {
    std::cout << "Test Prev Next Error : next for 5 is 6\n";
	std::cout << "\tbut we have : next = " << my_tree.next(5) << "\n";
    my_tree.printLikeTree();
	return;
  }
  if (my_tree.next(9) != 10)
  {
    std::cout << "Test Prev Next Error : next for 9 is 10\n";
	std::cout << "\tbut we have : next = " << my_tree.next(9) << "\n";
    my_tree.printLikeTree();
	return;
  }
  if (my_tree.next(7) != 9)
  {
    std::cout << "Test Prev Next Error : next for 7 is 9\n";
	std::cout << "\tbut we have : next = " << my_tree.next(7) << "\n";
    my_tree.printLikeTree();
	return;
  }
  if (my_tree.next(1) != 2)
  {
    std::cout << "Test Prev Next Error : next for 1 is 2\n";
	std::cout << "\tbut we have : next = " << my_tree.next(1) << "\n";
    my_tree.printLikeTree();
	return;
  }

  /// prev section
  if (my_tree.prev(1) != INT_MIN)
  {
    std::cout << "Test Prev Next Error : prev for 1 is INT_MIN\n";
	std::cout << "\tbut we have : prev = " << my_tree.prev(1) << "\n";
    my_tree.printLikeTree();
	return;
  }
  if (my_tree.prev(11) != 10)
  {
    std::cout << "Test Prev Next Error : prev for 11 is 10\n";
	std::cout << "\tbut we have : prev = " << my_tree.prev(11) << "\n";
    my_tree.printLikeTree();
	return;
  }
  if (my_tree.prev(9) != 7)
  {
    std::cout << "Test Prev Next Error : prev for 9 is 7\n";
	std::cout << "\tbut we have : prev = " << my_tree.prev(9) << "\n";
    my_tree.printLikeTree();
	return;
  }
  if (my_tree.prev(4) != 3)
  {
    std::cout << "Test Prev Next Error : prev for 4 is 3\n";
	std::cout << "\tbut we have : prev = " << my_tree.prev(4) << "\n";
    my_tree.printLikeTree();
	return;
  }
  if (my_tree.prev(6) != 5)
  {
    std::cout << "Test Prev Next Error : prev for 6 is 5\n";
	std::cout << "\tbut we have : prev = " << my_tree.prev(6) << "\n";
    my_tree.printLikeTree();
	return;
  }
  std::cout << "Test Prev Next : OK\n";
}



void TestErase (BinTree & my_tree)
{
  //std::cout << "\t\tERASE TEST\n";
  my_tree.erase(10);
  //std::cout << "AFTER ERASING ...\n";
  //my_tree.printLikeTree();
  //std::cout << "\n\n";
  my_tree.erase(2);
  my_tree.erase(3);
  my_tree.erase(5);
  my_tree.erase(9);
  my_tree.erase(11);
  my_tree.erase(7);
  my_tree.erase(4);
  my_tree.erase(3);
  my_tree.erase(1);
  my_tree.erase(6);
  std::cout << "Test Erase : OK\n";
}



void TestAll()
{
  BinTree my_tree;

  TestInsert(my_tree);
  TestFindAfterInsert(my_tree);
  TestCopy(my_tree);
  TestPrevNext(my_tree);
  TestErase(my_tree);
}
