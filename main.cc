#include "simulator.h"

int main () {
  Tape tape;
  tape.InfoCell(10, 10);

  Ant ant (5, 5, static_cast<Direction>(3)); 
  Simulator sim(tape, ant);

  sim.run();

}