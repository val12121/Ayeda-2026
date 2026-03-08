#include "ant.h"
#include "tape.h"

int Ant::get_color( Tape* tape ) const { return tape->get_color(x_, y_); }

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

void Ant::step(Tape* tape) {
  if (tape->get_color(x_, y_) == true) {  // if color == black
    turnRight();
    tape->SetCell(x_, y_, false);
  } else {  // if color == white
    turnLeft();
    tape->SetCell(x_, y_, true);
  }
  move();
}