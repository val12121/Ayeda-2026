#include <iostream>
#include "simulator.h"

int main() 
{
  Tape tape (10, 10, "DDII");

  std::cout << tape << endl;
  return 0;

}