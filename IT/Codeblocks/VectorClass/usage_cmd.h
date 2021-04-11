#include "Vector.h"

#define MAX_CMD_LEN 15 /// 13 characters of command + \n + \0
#include <cstring>

void Usage() {
    std::cout << "Usage :\n\n"
    << "help / man             Print usage.\n" 
    << "push                   Push element to vector.\n"
    << "insert                 Insert element to (sorted) vector.\n"
    << "insert                 Insert element at particular position.\n"
    << "size                   Get size of vector.\n"
    << "resize                 Set new size of vector.\n"
    << "find                   Find element in vector.\n"
    << "element                Return element from particular positionr.\n"
    << "pop                    Pop element from the end of vector.\n"
    << "erase                  Erase element from paticular position.\n"
    << "clear                  Clear vector.\n"
    << "print                  Print vector.\n"
    << "stop / exit            Stop the game.\n\n" << std::endl;
}

template<typename T>
int ParseCommand (Vector<T> & v) {
  int item;
  unsigned index, new_size;
  std::string line, cmd(MAX_CMD_LEN, '\0'), params;
    
  /// read line, make correct command
  getline(std::cin, line, '\n');
  if (line == "") {
    return 0;
  }
  unsigned i, j = 0;
  for (i = 0; line[i] == ' '; ++i);
  for (j = 0; line[i]; ++i) {
    if ((line[i] != ' ') ||
        (line[i + 1] != ' ')) {
      cmd[j] = line[i];
      ++j;
    }
  }
  cmd.resize(j);
  //cout << "cmd.size() = " << cmd.size() << endl;
  //cout << "cmd.length = " << cmd.length() << endl;

  /// check command
  if (cmd == "") {
    return 0;
  } else if (cmd == "help" || cmd == "man") {
    std::cout << std::endl;
    Usage();
  } else if (cmd == "push") {
    std::cout << "item to push : ";
    std::cin >> item;
    std::getline(std::cin, params);
    v.push(item);
  } else if (cmd == "insert") {
    std::cout << "item to insert in (sorted) vector : ";
    std::cin >> item;
    std::getline(std::cin, params);
    v.insert(item);
  } else if (cmd == "insert index") {
    std::cout << "item to insert in vector : ";
    std::cin >> item;
    std::getline(std::cin, params);
    std::cout << "index to insert in vector : ";
    std::cin >> index;
    v.insert(item, index);
  } else if (cmd == "size") {
    std::cout << "size = " << v.size() << std::endl;
  } else if (cmd == "resize") {
    std::cout << "new size of vector : ";
    std::cin >> new_size;
    std::getline(std::cin, params);
    v.resize(new_size);
  } else if (cmd == "find") {
    std::cout << "element to find : ";
    std::cin >> item;
    std::getline(std::cin, params);
    std::cout << "index of element = " << v.find(item) << std::endl;
  } else if (cmd == "element") {
    std::cout << "index element to find : ";
    std::cin >> index;
    std::getline(std::cin, params);
    std::cout << "element at \"index\" position = " << v[index] << std::endl;
  } else if (cmd == "pop") {
    std::cout << "element was popped : " << v.pop() << std::endl;
  } else if (cmd == "erase") {
    std::cout << "index of element to erase : ";
    std::cin >> index;
    std::getline(std::cin, params);
    std::cout << "element was erased : " << v.erase(index) << std::endl;
  } else if (cmd == "clear") {
    v.clear();
  } else if (cmd == "print") {
    std::cout << v << std::endl;
  } else if (cmd == "stop" || cmd == "exit") {
    return 1;
  } else {
    return -1; /// Wrong command
  }
  if (params != "") {
    std::cout << "from params : error" << std::endl;
    return -1;
  }
  return 0;
}


