#include "simulator.h"

void Simulator::run() {
  while (!isFinished()) {
    for (int i = 0; i < tape_.get_max_sizeX(); i++) {
      for (int j = 0; j < tape_.get_max_sizeY(); j++) {
        if (ant_.getx() == i && ant_.gety() == j) {
          std::cout << ant_;
        } else {
          std::cout << (tape_.get_color(i, j) ? "[X]" : "[ ]");
        }
      }
      std::cout << '\n';
    }
    std::cout << "Steps: " << steps_ << "\n";
    std::cin.get();

    ant_.step(tape_);
    steps_++;
  }
}