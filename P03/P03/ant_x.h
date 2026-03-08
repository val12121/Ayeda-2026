#pragma once
#include "ant.h"
#include "tape_periodic.h"
#include "tape_reflective.h"

class Ant_X : public Ant {
  public:
  Ant_X () {}
  Ant_X (int x, int y, Direction dir, std::string lado) : Ant (x, y, dir, lado) {}
  void step (Tape* tape) override;

  friend std::ostream& operator<<(std::ostream& os, const Ant_X& ant) {
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

  private:

};