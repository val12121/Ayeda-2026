#include <iostream>
#include <vector>
#include "colors.h"

using namespace std;
class Tape
{
private:
  int color_ = 0;
  int sizeX_ = 20;
  int sizeY_ = 20;
  vector<vector<int>> tape_;
  std::string dir_ = "DIDI";

public:
  Tape() : tape_(sizeX_, vector<int>(sizeY_, 0))
  {
    // std::cout << tape_.size() << std::endl;
  }

  Tape(int sizeX, int sizeY, std::string dir)
  {
    sizeX_ = sizeX;
    sizeY_ = sizeY;
    dir_ = dir;

    tape_.resize(sizeX);
    for (int i = 0; i < sizeX; ++i)
    {
      tape_[i].resize(sizeY, false);
    }
  }

  std::string next_color(int x, int y)
  {
    std::string color;
    switch (get_color(x, y))
    {
    case 0:
      SetCell(x, y, 1);
      color = BG_WHITE;
      break;

    case 1:
      SetCell(x, y, 2);
      color = BG_BLUE;
      break;

    case 2:
      SetCell(x, y, 3);
      color = BG_BLACK;
      break;

    case 3:
      SetCell(x, y, 0);
      color = BG_MAGENTA;
      break;

    default:
      break;
    }

    return color;
  }

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

  // Getters
  int get_color(int x, int y) const { return tape_[x][y]; }
  int get_max_sizeX() const { return sizeX_; }
  int get_max_sizeY() const { return sizeY_; }
  char get_dir(int color) const { return dir_[color]; };
  const vector<vector<int>> &get_tape() const { return tape_; } // Reference

  std::string show_color(int x, int y)
  {
    std::string result;
    if (get_tape()[x][y] == 0) {
      result = BG_MAGENTA;
    }
    else if (get_tape()[x][y] == 1)
    {
      result = BG_WHITE;
    }
    else if (get_tape()[x][y] == 2)
    {
      result = BG_BLUE;
    }
    else if (get_tape()[x][y] == 3)
    {
      result = BG_BLACK;
    }
    return result;
  };
  // Setter
  void InfoCell(int posX, int posY);

  // Change Color of the Cell
  void SetCell(int posX, int posY, int color);
};
