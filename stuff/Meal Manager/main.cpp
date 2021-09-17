#include <iostream>
#include <vector>

#include "cmd_types.h"
#include "meal.h"
#include "manage_cmd.h"
#include "usage.h"

int main() {
  CommandType cmd;
  std::string command;
  getline(std::cin, command);
  cmd = static_cast<CommandType>(CheckCommand(command));
  ExecuteCommand(command);
  return 0;
}

