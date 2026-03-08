#include "ant_x.h"

class Ant_Carnivore : public Ant_X {
  public:
    Ant_Carnivore(int x, int y, Direction dir, std::string lado) : Ant_X(x, y, dir, lado) {}
    void Eat( double food ) override { LifeTime = LifeTime + (voracity)/100 * food; }
    std::string ant_type() override { return "Car"; }
    double get_voracity() { return voracity; }
    void step(Tape *tape) override;
  protected:
    double voracity = 20; 
    void move() override;
};