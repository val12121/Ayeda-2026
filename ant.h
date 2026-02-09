#pragma once
#include <iostream>

#include "Tape.h"
#include "colors.h"

enum class Direction { Left = 0, Right, Up, Down };
class Ant {
 public:
  Ant() {};
  Ant(int x, int y, Direction dir) : x_(x), y_(y), dir_(dir) {}

  void step(Tape& tape);

  friend std::ostream& operator<<(std::ostream& os, const Ant& ant) {
    switch (ant.dir_) {
      case Direction::Left:
        os << BG_RED << "[<]" << RESET;
        break;
      case Direction::Right:
        os << BG_RED << "[>]" << RESET;
        break;
      case Direction::Up:
        os << BG_RED << "[^]" << RESET;
        break;
      case Direction::Down:
        os << BG_RED << "[v]" << RESET;
        break;
    }
    return os;
  }

  // Setters
  void setx(int x) { x_ = x; }
  void sety(int y) { y_ = y; }

  // Getters
  int getx() const { return x_; }
  int gety() const { return y_; }

  int get_dir() { return static_cast<int>(dir_); }

  void InfoAnt() {
    std::cout << "pos (" << getx() << ", " << gety() << ")\n";
    std::cout << "Direction " << static_cast<int>(dir_) << endl;
  }

 private:
  int x_, y_;
  Direction dir_;

  void turnLeft();
  void turnRight();
  void move();
};
