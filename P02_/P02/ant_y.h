#include "ant_x.h"

class Ant_Y : public Ant_X
{
public:
  Ant_Y(int x, int y, Direction dir, std::string lado, bool flag) : Ant_X(x, y, dir, lado)
  {
    flag_ = flag;
  }

  void Changeflag(bool valor) { flag_ = valor; }

private:
  bool flag_;
  void step() override
  {
    if (flag == true)
    {
      std::cout << x_ << " " << y_ << endl;

      if (tape.get_color(x_, y_) == 0)
      { // If color == magenta
        if (get_dir(0) == 'D')
        {
          turnRight();
        }
        else
        {
          turnLeft();
        }
        tape.SetCell(x_, y_, 1);
      }
      else if (tape.get_color(x_, y_) == 1)
      { // If color == white
        if (get_dir(1) == 'D')
        {
          turnRight();
        }
        else
        {
          turnLeft();
        }
        tape.SetCell(x_, y_, 2);
      }
      else if (tape.get_color(x_, y_) == 2)
      { // If color == blue
        if (get_dir(2) == 'D')
        {
          turnRight();
        }
        else
        {
          turnLeft();
        }
        tape.SetCell(x_, y_, 3);
      }
      else if (tape.get_color(x_, y_) == 3)
      { // If color == black
        if (get_dir(3) == 'D')
        {
          turnRight();
        }
        else
        {
          turnLeft();
        }
        tape.SetCell(x_, y_, 2);
      }
      this->move();
    }
  }
};