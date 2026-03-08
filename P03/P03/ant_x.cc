#include "ant_x.h"

void Ant_X::step(Tape* tape) {
  std::cout << x_ << " " << y_ << endl;
  
  if (tape->get_color(x_, y_) == 0) { // If color == magenta
    if ( get_dir(0) == 'D') { turnRight(); } else { turnLeft(); }
    tape->SetCell(x_, y_, 1);

  } else if (tape->get_color(x_, y_) == 1) {  // If color == white
    if ( get_dir(1) == 'D') { turnRight(); } else { turnLeft(); }
    tape->SetCell(x_, y_, 2);

  } else if (tape->get_color(x_, y_) == 2) { // If color == blue
    if ( get_dir(2) == 'D') { turnRight(); } else { turnLeft(); }
    tape->SetCell(x_, y_, 3);

  } else if (tape->get_color(x_, y_) == 3) { // If color == black
    if ( get_dir(3) == 'D') { turnRight(); } else { turnLeft(); }
    tape->SetCell(x_, y_, 0);
  }
  this -> move();
}