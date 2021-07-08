#include <iostream>
#include <sstream>
#include <map>

/// DEPOSIT name sum
/// WITHDRAW name sum
/// BALANCE name
/// TRANSFER name1 name2 sum
/// INCOME percent

using Info = std::map<std::string, long long>;

void operation(const std::string & op, std::stringstream & ss, Info & io);

void balance  (const std::string & name, const Info & io);
void income   (long long percent, Info & io);
void deposit  (const std::string & name, long long sum, Info & io);
void withdraw (const std::string & name, long long sum, Info & io);

int main () {
  std::string cmd, op;
  Info io;
  
  while (getline(std::cin, cmd)) {
    std::stringstream ss(cmd);
    ss >> op;
    operation (op, ss, io);
  }
  
  return 0;
}


void operation(const std::string & op, std::stringstream & ss, Info & io) {
  std::string name, name1, name2;
  long long sum, percent;
  if (op == "BALANCE")
  {
    ss >> name;
    balance(name, io);
  }
  else
  if (op == "INCOME")
  {
    ss >> percent;
    income(percent, io);
  }
  else
  if (op == "DEPOSIT")
  {
    ss >> name >> sum;
    deposit(name, sum, io);
  }
  else
  if (op == "WITHDRAW")
  {
    ss >> name >> sum;
    withdraw(name, sum, io);
  }
  else
  if (op == "TRANSFER")
  {
    ss >> name1 >> name2 >> sum;
    withdraw(name1, sum, io);
    deposit(name2, sum, io);
  }
}



void balance  (const std::string & name, const Info & io)
{
  if (io.find(name) != io.end()) 
  {
    std::cout << io.at(name) << "\n";    
  }
  else
  {
    std::cout << "ERROR\n";
  }
}



void income (long long percent, Info & io)
{
  for (auto & personInfo : io)
  {
    long long & sum = personInfo.second;
    if (sum > 0)
    {
      sum = sum * (100 + percent) / 100;
    }
  }
}



void deposit (const std::string & name, long long sum, Info & io)
{
  io[name] += sum;
}



void withdraw (const std::string & name, long long sum, Info & io)
{
  io[name] -= sum;
}
