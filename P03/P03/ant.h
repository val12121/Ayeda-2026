#pragma once
#include <iostream>
#include "colors.h"

class Tape;

enum class Direction { Left = 0, Right, Up, Down };
class Ant {
  public:
  Ant() {};
  Ant(int x, int y, Direction dir, std::string lado) : x_(x), y_(y), dir_(dir), lado_{lado} {}

  virtual ~Ant() {}

  virtual void step(Tape* tape);

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
  void setdir(int dir) { 
    switch (dir) {
    case 0:
      dir_ = Direction::Left;
      break;
    case 1:
      dir_ = Direction::Right;
      break;
    case 2:
      dir_ = Direction::Up;
      break;
    case 3:
      dir_ = Direction::Down;
      break;
    }
  }

  // Getters
  int getx() const { return x_; }
  int gety() const { return y_; }
  int get_color( Tape* tape ) const; 
  char get_dir(int color) const { return lado_[color]; };

  int get_dir() { return static_cast<int>(dir_); }
  double get_life() { return LifeTime; }
  virtual std::string ant_type() { return ""; }

  virtual void Eat( double food ) { }
  virtual void Damage( int per ) {}
  virtual double get_voracity() { return 0; }


  void InfoAnt() {
    std::cout << "pos (" << getx() << ", " << gety() << ")\n";
    std::cout << "Direction " << static_cast<int>(dir_) << std::endl;
  }

  protected:
  int x_, y_;
  int size_x, size_y;
  double LifeTime = 100; 
  Direction dir_;
  std::string lado_;

  void turnLeft();
  void turnRight();
  virtual void move();
};
