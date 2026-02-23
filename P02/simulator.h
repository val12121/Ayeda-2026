#pragma once
#include "ant_x.h"

class Simulator {
 public:
  Simulator(const Tape& tape, const Ant& ant) : tape_(tape), ant_(ant), steps_(0) {
    option_ = 0;
  };
  Simulator(const Tape& tape, const Ant_X& ant) : tape_(tape), ant_x_(ant), steps_(0) {
    option_ = 1;
  };

  void run();
  void run_x();

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
  int option_;
  Tape tape_;
  Ant ant_;
  Ant_X ant_x_;
  int steps_;

  void step() { steps_++; };
  bool isFinished() {
    return ant_.getx() < 0 || ant_.gety() < 0 ||
           ant_.getx() >= tape_.get_max_sizeX() ||
           ant_.gety() >= tape_.get_max_sizeY();
  };

  bool isFinishedX() {
    std::cout << ant_x_.getx() << endl;
    return ant_x_.getx() < 0 || ant_x_.gety() < 0 ||
           ant_x_.getx() >= tape_.get_max_sizeX() ||
           ant_x_.gety() >= tape_.get_max_sizeY();
  };
};