#pragma once
#include "tape.h"
#include "ant_x.h"

class TapeReflective : public Tape {
  public:
  TapeReflective(int sizeX, int sizeY) : Tape(sizeX, sizeY) {}
  bool switcher(Ant *ant)
  {
    ant->InfoAnt();
    std::cout << this->get_max_sizeX() << std::endl;
    if (ant->getx() >= this->get_max_sizeX()) {
      ant->setx(this->get_max_sizeX() - 1);
      ant->setdir(0);
      return false;
    }
    else if (ant->getx() < 0 ) {
      ant->setx(0);
      ant->setdir(1);
      return false;
    }
    else if (ant->gety() >= this->get_max_sizeY()) {
      ant->sety(this->get_max_sizeY() - 1);
      ant->setdir(3);
      return false;
    }
    else if (ant->gety() < 0 ) {
      ant->sety(0);
      ant->setdir(2);
      return false;
    }
    return false;
  }
};