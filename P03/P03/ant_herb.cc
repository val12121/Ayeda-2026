#include "ant_herb.h"

void Ant_Herbivore::step(Tape *tape) 
{

  if (tape->get_color(x_, y_) == 0) { // If color == magenta
    if (get_dir(0) == 'D') {
      turnRight();
    } else {
      turnLeft();
    }
    tape->SetCell(x_, y_, 1);
  } else if (tape->get_color(x_, y_) == 1) { // If color == white
    if (get_dir(1) == 'D') {
      turnRight();
    } else {
      turnLeft();
    }
    LifeTime++;
    tape->SetCell(x_, y_, 2);
  } else if (tape->get_color(x_, y_) == 2) { // If color == blue
    if (get_dir(2) == 'D') {
      turnRight();
    } else {
      turnLeft();
    }
    LifeTime += 2;
    tape->SetCell(x_, y_, 3);
    
  }
  else if (tape->get_color(x_, y_) == 3) { // If color == black
    if (get_dir(3) == 'D') {
      turnRight();
    } else {
      turnLeft();
    }
    LifeTime += 3;
    tape->SetCell(x_, y_, 0);
  }
  this->move();
  LifeTime--;

  std::cout << "Tipo de hormiga: " << ant_type() << ", pos: ";
  std::cout << x_ << " " << y_ << " Lifetime: "<< LifeTime;
  std::cout << " Dir: "<< static_cast<int>(dir_) << std::endl;
}
