#pragma once
#include "ant.h"

class Simulator {
 public:
  Simulator(const Tape& tape, const Ant& ant)
      : tape_(tape), ant_(ant), steps_(0) {};
  void run() {
    while (!isFinished()) {
      // Dibujar
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

 private:
  Tape tape_;
  Ant ant_;
  int steps_;

  void step() { steps_++; };
  bool isFinished() {
    if (ant_.getx() == tape_.get_max_sizeX() ||
        ant_.gety() == tape_.get_max_sizeY()) {
      return true;
    } else if (ant_.getx() == 0 || ant_.gety() == 0) {
      return true;
    } else {
      return false;
    }
  };
};