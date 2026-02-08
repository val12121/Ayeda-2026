#pragma once
#include <iostream>

#include "Tape.h"

enum class Direction {Left = 0, Up, Right, Down};

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

  friend std::ostream& operator<<(std::ostream&, const Ant&);
  
  //Setters
  void setx( int x ) { x_ = x; }
  void sety( int y ) { y_ = y; }

  //Getters
  int getx() const { return x_; }
  int gety() const { return y_; }

  void InfoAnt() {
    std::cout << "pos (" << getx() << ", " << gety() << ")\n";
    std::cout << "Direction " << static_cast<int>(dir_) << endl;
  }

 private:
  int x_, y_;
  Direction dir_;
  
  void turnLeft() { 
    if ( static_cast<int>(dir_) >= 1) { 
      dir_ = static_cast<Direction>(static_cast<int>(dir_) - 1);
    } else { dir_ = static_cast<Direction>(3); }
  }

  void turnRight() {
    if ( static_cast<int>(dir_) < 3) { 
      dir_ = static_cast<Direction>(static_cast<int>(dir_) + 1);
    } else { 
      dir_ = static_cast<Direction>(0); 
    }
  }
  
  void move() {
    int dir1 = static_cast<int>(dir_);
    switch (dir1) {
      case 0: 
          setx(getx() - 1);
        break;
      case 1:
          sety(gety() + 1);
        break;
      case 2:
          setx(getx() + 1);
        break;
      case 3:
          sety(gety() - 1);
        break;
      default:
        break;
    }
  }
};