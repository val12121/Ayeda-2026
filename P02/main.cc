#include "simulator.h"

int main() 
{
  Tape tape (10, 20, "DDII");
  int x = 5, y = 5;
  Ant_X ant(x, y, Direction{1});

  Simulator simulator (tape, ant);
  simulator.run_x();

  return 0;

}