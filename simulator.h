#pragma once
#include "ant.h"
#include "tape.h"

class Simulator {
 public:
  Simulator(const Tape& tape, const Ant& ant)
      : tape_(tape), ant_(ant), steps_(0) {}
  void run();

 private:
  Tape tape_;
  Ant ant_;
  int steps_;

  void step();
  bool isFinished() const;
};