#include "tape.h"
#include <cassert>
#include <assert.h>

void Tape::InfoCell(int posX, int posY) {
  assert(get_max_sizeX() > posX && get_max_sizeY() > posY);
  cout << "The cell is ";
  if (tape_[posX][posY] == 0) cout << "red";
  else if (tape_[posX][posY] == 1) cout << "white";
  else if (tape_[posX][posY] == 2) cout << "blue";
  else if (tape_[posX][posY] == 2) cout << "black";
  cout << endl;
}

void Tape::SetCell(int posX, int posY, int color) {
  assert(get_max_sizeX() > posX && get_max_sizeY() > posY);
  tape_[posX][posY] = color;
}
