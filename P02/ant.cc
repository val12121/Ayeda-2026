#include "ant.h"

void Ant::turnLeft() {
  switch (dir_) {
    case Direction::Up:
      dir_ = Direction::Left;
      break;
    case Direction::Left:
      dir_ = Direction::Down;
      break;
    case Direction::Down:
      dir_ = Direction::Right;
      break;
    case Direction::Right:
      dir_ = Direction::Up;
      break;
  }
}

void Ant::turnRight() {
  switch (dir_) {
    case Direction::Up:
      dir_ = Direction::Right;
      break;
    case Direction::Right:
      dir_ = Direction::Down;
      break;
    case Direction::Down:
      dir_ = Direction::Left;
      break;
    case Direction::Left:
      dir_ = Direction::Up;
      break;
  }
}

void Ant::move() {
  switch (dir_) {
    case Direction::Left:
      sety(gety() - 1);
      break;
    case Direction::Up:
      setx(getx() - 1);
      break;
    case Direction::Right:
      sety(gety() + 1);
      break;
    case Direction::Down:
      setx(getx() + 1);
      break;
    default:
      break;
  }
}

void Ant::step(Tape& tape) {
  if (tape.get_color(x_, y_) == 0) { // If color == magenta
    if ( tape.get_dir(0) == 'D') { turnRight(); } else { turnLeft(); }
    tape.SetCell(x_, y_, 1);

  } else if (tape.get_color(x_, y_) == 1) {  // If color == white
    if ( tape.get_dir(1) == 'D') { turnRight(); } else { turnLeft(); }
    tape.SetCell(x_, y_, 2);

  } else if (tape.get_color(x_, y_) == 2) { // If color == blue
    if ( tape.get_dir(2) == 'D') { turnRight(); } else { turnLeft(); }
    tape.SetCell(x_, y_, 3);

  } else if (tape.get_color(x_, y_) == 3) { // If color == black
    if ( tape.get_dir(3) == 'D') { turnRight(); } else { turnLeft(); }
    tape.SetCell(x_, y_, 0);
  }
  move();
}