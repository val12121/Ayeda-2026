#include "ant_x.h"

class Ant_Herbivore : public Ant_X
{
public:
  Ant_Herbivore(int x, int y, Direction dir, std::string lado) : Ant_X(x, y, dir, lado) {}
  void step(Tape *tape) override;
  std::string ant_type() override { return "Her"; }
  void Damage( int per ) override { LifeTime = (LifeTime * (100 - per)) / 100; }

private:
  bool alive = true;
};
