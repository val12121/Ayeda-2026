#include "simulator.h"

void Simulator::run() {
  while (!isFinished()) {
    for (int i = 0; i < tape_.get_max_sizeX(); i++) {
      for (int j = 0; j < tape_.get_max_sizeY(); j++) {
        if (ant_.getx() == i && ant_.gety() == j) {
          std::cout << tape_.show_color(i, j) << ant_ << RESET;
        } else {
          std::cout << (tape_.show_color(i, j)) << " " << RESET;
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

void Simulator::run_x() {
  //std::cout << "Hola" << std::endl;
  while (!isFinishedX()) {
    for (int i = 0; i < tape_.get_max_sizeX(); i++) {
      for (int j = 0; j < tape_.get_max_sizeY(); j++) {
        if (ant_x_.getx() == i && ant_x_.gety() == j) {
          std::cout << tape_.show_color(i, j) << ant_x_ << RESET;
        } else {
          std::cout << (tape_.show_color(i, j)) << " " << RESET;
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