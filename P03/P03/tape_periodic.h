#pragma once
#include "tape.h"
#include "ant_x.h"

class TapePeriodic : public Tape
{
public:
  TapePeriodic(int sizeX, int sizeY) : Tape(sizeX, sizeY) {}
  bool switcher(Ant *ant) override
  {
    int dir = ant->get_dir();
    //ant->InfoAnt();
    //std::cout << this->get_max_sizeX() << std::endl;
    if (ant->getx() >= this->get_max_sizeX()) {
      std::cout << "Periodic" << " " << ant->ant_type() << " " << dir << std::endl;
      ant->setx(0);
    }
    else if (ant->getx() < 0 ) {
      std::cout << "Periodic" << " " << ant->ant_type() << " " << dir << std::endl;
      ant->setx(this->get_max_sizeX() - 1);
    }
    else if (ant->gety() >= this->get_max_sizeY()) {
      std::cout << "Periodic" << " " << ant->ant_type() << " " << dir << std::endl;
      ant->sety(0);
    }
    else if (ant->gety() < 0 ) {
      std::cout << "Periodic" << " " << ant->ant_type() << " " << dir << std::endl;
      ant->sety(this->get_max_sizeY() - 1);
    }
    return false; 
  }
};