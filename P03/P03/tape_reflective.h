#pragma once
#include "tape.h"
#include "ant_x.h"

class TapeReflective : public Tape {
  public:
  TapeReflective(int sizeX, int sizeY) : Tape(sizeX, sizeY) {}
  bool switcher(Ant *ant)
  {
    int dir = ant->get_dir();
    //ant->InfoAnt();
    //std::cout << this->get_max_sizeX() << std::endl;
    if (ant->getx() >= this->get_max_sizeX()) {
      std::cout << "Reflejo" << " " << ant->ant_type() << " " << dir  << std::endl;
      ant->setx(this->get_max_sizeX() - 1);
      ant->setdir(2);
      ant->InfoAnt();
      return false;
    }
    else if (ant->getx() < 0 ) {
      std::cout << "Reflejo" << " " << ant->ant_type() << " " << dir  << std::endl;
      ant->setx(0);
      ant->setdir(3);
      ant->InfoAnt();
      return false;
    }
    else if (ant->gety() >= this->get_max_sizeY()) {
      std::cout << "Reflejo" << " " << ant->ant_type() << " " << dir  << std::endl;
      ant->sety(this->get_max_sizeY() - 1);
      ant->setdir(0);
      ant->InfoAnt();

      return false;
    }
    else if (ant->gety() < 0 ) {
      std::cout << "Reflejo" << " " << ant->ant_type() << " " << dir  << std::endl;
      ant->sety(0);
      ant->setdir(1);
      ant->InfoAnt();
      return false;
    }
    return false;
  }
};