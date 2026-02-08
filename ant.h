#pragma once
#include <iostream>

#include "Tape.h"
#include "colors.h"

enum class Direction {Left = 0, Right, Up, Down};

class Ant {
 public:
  Ant() {};
  Ant(int x, int y, Direction dir) : x_(x), y_(y), dir_(dir) {}
  
  void step(Tape& tape) {
    if (tape.get_color(x_, y_) == true) { // if color == black
      turnRight();
      tape.SetCell(x_, y_, false);
    } else { //if color == white
      turnLeft();    
      tape.SetCell(x_, y_, true);
    }
    move();
  }

  friend std::ostream& operator<<(std::ostream& os, const Ant& ant) {
    switch (ant.dir_) {
      case Direction::Left: 
          os << BG_RED << "[<]" << RESET; 
        break;
      case Direction::Right:
          os << BG_RED << "[>]" << RESET;
        break;
      case Direction::Up:
          os << BG_RED << "[^]" << RESET;
        break;
      case Direction::Down:
          os << BG_RED << "[v]" << RESET;
        break;
      default:
        break;
    }
    return os;
  }
  
  //Setters
  void setx( int x ) { x_ = x; }
  void sety( int y ) { y_ = y; }

  //Getters
  int getx() const { return x_; }
  int gety() const { return y_; }

  int get_dir() { return static_cast<int>(dir_); }

  void InfoAnt() {
    std::cout << "pos (" << getx() << ", " << gety() << ")\n";
    std::cout << "Direction " << static_cast<int>(dir_) << endl;
  }

 private:
  int x_, y_;
  Direction dir_;
  
  void turnLeft() { 
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

  void turnRight() {
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
  
  void move() {
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
};