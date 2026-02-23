#include "simulator.h"
#include <string>
#include <sstream>

int main(int argc, char *argv[]) 
{
  Tape tape (10, 20, "DDII");
  int x = 5, y = 5;
  Ant* ant;

  ant = new Ant_X(x, y, Direction{2});

  Simulator simulator (tape, ant);
  simulator.run();

  return 0;
}