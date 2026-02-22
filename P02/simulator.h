#pragma once
#include "ant.h"

class Simulator {
 public:
  Simulator(const Tape& tape, const Ant& ant)
      : tape_(tape), ant_(ant), steps_(0) {};
  void run();

  Tape get_tape() const { return tape_; }
  Ant get_ant() const { return ant_; }

  friend std::ostream& operator<<(std::ostream& os, const Simulator& sim) {
    for (int i = 0; i < sim.get_tape().get_max_sizeX(); i++) {
      for (int j = 0; j < sim.get_tape().get_max_sizeY(); j++) {
        if (sim.get_ant().getx() == i && sim.get_ant().gety() == j) {
          os << sim.get_tape().show_color(i, j) << sim.get_ant() << RESET;
        } else {
          os << (sim.get_tape().show_color(i, j)) << " " << RESET;
        }
      }
      os << '\n';
    }
    return os;
  }

 private:
  Tape tape_;
  Ant ant_;
  int steps_;

  void step() { steps_++; };
  bool isFinished() {
    return ant_.getx() < 0 || ant_.gety() < 0 ||
           ant_.getx() >= tape_.get_max_sizeX() ||
           ant_.gety() >= tape_.get_max_sizeY();
  };
};