#pragma once
#include <iostream>

#include "Tape.h"

enum class Direction { Left, Up, Right, Down };

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
      dir_ = static_cast<Direction>(static_cast<int>(dir_) - 1);
    } else { dir_ = static_cast<Direction>(4); }
  }

  void turnRight() {
    if ( static_cast<int>(dir_) <= 3) { 
      dir_ = static_cast<Direction>(static_cast<int>(dir_) + 1);
    } else { dir_ = static_cast<Direction>(1); }
  }

  //Setters
  void setx( int x ) { x_ = x; }
  void sety( int y ) { y_ = y; }

  //Getters
  int getx() const { return x_; }
  int gety() const { return y_; }

  void move() {
    int dir1 = static_cast<int>(dir_);
    switch (dir1) {
      case 0: 
          setx(getx() - 1);
        break;
      case 1:
          sety(gety() + 1);
        break;
      case 2:
          setx(getx() + 1);
        break;
      case 3:
          sety(gety() - 1);
        break;
      default:
        break;
    }
  }
};