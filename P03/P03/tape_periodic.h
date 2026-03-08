#pragma once
#include "tape.h"
#include "ant_x.h"

class TapePeriodic : public Tape
{
public:
  TapePeriodic(int sizeX, int sizeY) : Tape(sizeX, sizeY) {}
  bool switcher(Ant *ant) override
  {
    ant->InfoAnt();
    std::cout << this->get_max_sizeX() << std::endl;
    if (ant->getx() >= this->get_max_sizeX()) {
      ant->setx(0);
    }
    else if (ant->getx() < 0 ) {
      ant->setx(this->get_max_sizeX() - 1);
    }
    else if (ant->gety() >= this->get_max_sizeY()) {
      ant->sety(0);
    }
    else if (ant->gety() < 0 ) {
      ant->sety(this->get_max_sizeY() - 1);
    }
    return false; 
  }
};