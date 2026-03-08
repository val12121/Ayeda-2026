#pragma once
#include "ant_herb.h"
#include "ant_car.h"
class Simulator
{
public:
  Simulator(Tape *tape, Ant *ant) : tape_(tape), ant_(ant), steps_(0) {}
  Simulator(std::string archivo);

  void run();
  Tape get_tape() const { return *tape_; }
  Ant *get_ant() const { return ant_; }

  friend std::ostream &operator<<(std::ostream &os, const Simulator &sim)
  {
    for (int i = sim.tape_->get_min_sizeX(); i < sim.tape_->get_max_sizeX(); i++)
    {
      for (int j = sim.tape_->get_min_sizeY(); j < sim.tape_->get_max_sizeY(); j++)
      {
        Ant *anty = nullptr;
        for (Ant *aux : sim.ants_)
        {
          if (aux->getx() == i && aux->gety() == j)
          {
            anty = aux;
            break;
          }
        }
        if (anty != nullptr)
        {
          os << sim.tape_->show_color(i, j) << *anty << RESET;
        }
        else
        {
          os << sim.tape_->show_color(i, j) << " " << RESET;
        }
      }
      os << '\n';
    }
    return os;
  }

  Direction charToDir(std::string c);
  void InfoAnts()
  {
    for (int i = 0; i < ants_.size(); i++)
    {
      ants_[i]->InfoAnt();
      std::cout << endl;
    }
  }

  int Save(const std::string& filename);

private:
  std::vector<Ant *> ants_;
  int option_;
  Tape *tape_;
  Ant *ant_;
  int steps_;

  void step() { steps_++; };
  bool isFinished()
  {
    for (Ant *a : ants_)
    {
      if (a->getx() < tape_->get_min_sizeX() || a->gety() < tape_->get_min_sizeY() ||
          a->getx() >= tape_->get_max_sizeX() ||
          a->gety() >= tape_->get_max_sizeY())
      {
        /*
        *1! return true; // Una se salió, fin del juego 
        */
        return (tape_->switcher(a));
      }
    }
    return false;
  }
};