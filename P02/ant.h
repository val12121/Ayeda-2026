#pragma once
#include <iostream>
#include "tape.h"
#include "colors.h"

enum class Direction { Left = 0, Right, Up, Down };
class Ant {
 public:
  Ant() {};
  Ant(int x, int y, Direction dir, Tape tape) : x_(x), y_(y), dir_(dir), tape_(tape) {}

  void step(Tape& tape);

  friend std::ostream& operator<<(std::ostream& os, const Ant& ant) {
    std::string next_color = ant.get_tape().next_color(ant.getx(), ant.gety());
    switch (ant.dir_) {
      case Direction::Left:
        os << next_color << "[<]" << RESET;
        break;
      case Direction::Right:
        os << next_color << "[>]" << RESET;
        break;
      case Direction::Up:
        os << next_color << "[^]" << RESET;
        break;
      case Direction::Down:
        os << next_color << "[v]" << RESET;
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
  Tape get_tape() const { return tape_; }

  void InfoAnt() {
    std::cout << "pos (" << getx() << ", " << gety() << ")\n";
    std::cout << "Direction " << static_cast<int>(dir_) << endl;
  }

 private:
  int x_, y_;
  int size_x, size_y;
  Direction dir_;
  Tape tape_;

  void turnLeft();
  void turnRight();
  void move();
};
