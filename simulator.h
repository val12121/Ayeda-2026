#pragma once
#include "ant.h"

class Simulator {
 public:
  Simulator(const Tape& tape, const Ant& ant)
      : tape_(tape), ant_(ant), steps_(0) {};
  void run();

 private:
  Tape tape_;
  Ant ant_;
  int steps_;

  void step() { steps_++; };
  bool isFinished() {
    return ant_.getx() < 0 || ant_.gety() < 0 || ant_.getx() >= tape_.get_max_sizeX() || ant_.gety() >= tape_.get_max_sizeY();
  };
};