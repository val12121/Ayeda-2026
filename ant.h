#pragma once
#include <iostream>

#include "Tape.h"

enum class Direction { Left, Right, Up, Down };

class Ant {
 public:
  Ant() {};
  Ant(int x, int y, Direction dir) : x_(x), y_(y), dir_(dir) {}
  void step(Tape& tape) {
    if (tape.get_color() == true) { // if color == black
      tape.set_color(false);
      turnRight();
    } else {
      tape.set_color(true);
      turnLeft();
    }
  }

  friend std::ostream& operator<<(std::ostream&, const Ant&);

 private:
  int x_, y_;
  Direction dir_;
  void turnLeft() { 
    if ( static_cast<int>(dir_) >= 1) { 
      dir_ = static_cast<Direction>(static_cast<int>(dir_) + 1);
    } //else { dir_ =  }   
  };
  void turnRight();
  void move();
};