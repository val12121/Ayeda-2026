#pragma once
#include <iostream>
#include <vector>
#include "colors.h"

class Ant;

using namespace std;
class Tape
{
private:
  int color_ = 0;
  int sizeX_ = 20;
  int sizeY_ = 20;
  vector<vector<int>> tape_;
  // std::string dir_ = "DI";

public:
  // Constructores
  Tape() : tape_(sizeX_, vector<int>(sizeY_, 0)) {}
  Tape(int sizeX, int sizeY)
  {
    sizeX_ = sizeX;
    sizeY_ = sizeY;

    tape_.resize(sizeX);
    for (int i = 0; i < sizeX; ++i)
    {
      tape_[i].resize(sizeY, false);
    }
  }

  virtual bool switcher (Ant* ant) { return false; }

  friend std::ostream &operator<<(std::ostream &os, const Tape &tape)
  {
    for (int i = 0; i < tape.get_max_sizeX(); i++)
    {
      for (int j = 0; j < tape.get_max_sizeY(); j++)
      {
        if (tape.get_tape()[i][j] == 0)
        {
          os << BG_MAGENTA << "  " << RESET;
        }
        else if (tape.get_tape()[i][j] == 1)
        {
          os << BG_WHITE << "  " << RESET;
        }
        else if (tape.get_tape()[i][j] == 2)
        {
          os << BG_BLUE << "  " << RESET;
        }
        else if (tape.get_tape()[i][j] == 3)
        {
          os << BG_BLACK << "  " << RESET;
        }
      }
      os << "\n";
    }
    return os;
  }
  std::string next_color(int x, int y);

  // Getters
  virtual int get_color(int x, int y) const { return tape_[x][y]; }
  virtual int get_max_sizeX() const { return sizeX_; }
  virtual int get_max_sizeY() const { return sizeY_; }
  virtual int get_min_sizeX() const { return 0; }
  virtual int get_min_sizeY() const { return 0; }

  const vector<vector<int>> &get_tape() const { return tape_; } // Reference

  virtual std::string show_color(int x, int y);
  void InfoCell(int posX, int posY);

  // Setter
  virtual void set_tape() {};
  // Change Color of the Cell
  virtual void SetCell(int posX, int posY, int color);
};
