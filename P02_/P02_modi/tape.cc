#include "tape.h"
#include <cassert>
#include <assert.h>

std::string Tape::next_color(int x, int y)
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

std::string Tape::show_color(int x, int y)
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

void Tape::InfoCell(int posX, int posY)
{
  assert(get_max_sizeX() > posX && get_max_sizeY() > posY);
  cout << "The cell is ";
  if (tape_[posX][posY] == 0)
    cout << "red";
  else if (tape_[posX][posY] == 1)
    cout << "white";
  else if (tape_[posX][posY] == 2)
    cout << "blue";
  else if (tape_[posX][posY] == 2)
    cout << "black";
  cout << endl;
}

void Tape::SetCell(int posX, int posY, int color)
{
  assert(get_max_sizeX() > posX && get_max_sizeY() > posY);
  tape_[posX][posY] = color;
}
