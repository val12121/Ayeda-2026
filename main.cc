#include "simulator.h"

int main () {
  Tape tape;
  tape.InfoCell(10, 10);

  Ant ant (5, 5, static_cast<Direction>(3)); 
  Simulator sim(tape, ant);

  sim.run();

  /*
  for (int i = 0; i < 10; i++) {
    ant.step(tape);
    ant.InfoAnt();
    std::cout << tape.get_color(ant.getx(), ant.gety()) << std::endl;
  }
  */
}