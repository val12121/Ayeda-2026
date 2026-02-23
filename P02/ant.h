#pragma once
#include <iostream>
#include "tape.h"
#include "colors.h"

enum class Direction { Left = 0, Right, Up, Down };
class Ant {
 public:
  Ant() {};
  Ant(int x, int y, Direction dir) : x_(x), y_(y), dir_(dir) {}

  virtual ~Ant() {}

  virtual void step(Tape& tape);

  friend std::ostream& operator<<(std::ostream& os, const Ant& ant) {
    switch (ant.dir_) {
      case Direction::Left:
        os << "<";
        break;
      case Direction::Right:
        os << ">";
        break;
      case Direction::Up:
        os << "^";
        break;
      case Direction::Down:
        os << "v";
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
  int get_color( Tape& tape ) const { return tape.get_color(x_, y_); }

  int get_dir() { return static_cast<int>(dir_); }

  void InfoAnt() {
    std::cout << "pos (" << getx() << ", " << gety() << ")\n";
    std::cout << "Direction " << static_cast<int>(dir_) << endl;
  }

  protected:
  int x_, y_;
  int size_x, size_y;
  Direction dir_;

  void turnLeft();
  void turnRight();
  void move();
};
