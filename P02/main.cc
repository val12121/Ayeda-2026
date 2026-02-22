#include "simulator.h"

int main() 
{
  Tape tape (10, 10, "DDII");
  int x = 5, y = 5;
  Ant ant(x, y, Direction{1});

  Simulator simulator (tape, ant);
  simulator.run();


  std::cout << tape << endl;
  return 0;

}