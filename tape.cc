#include "tape.h"
#include <cassert>
#include <assert.h>

void Tape::InfoCell(int posX, int posY) {
  //assert(get_max_sizeX() > posX && get_max_sizeY() > posY);
  cout << "The cell is ";
  tape_[posX][posY] ? cout << "black" : cout << "white";
  cout << endl;
}

void Tape::SetCell(int posX, int posY, bool color) {
  //assert(get_max_sizeX() > posX && get_max_sizeY() > posY);
  tape_[posX][posY] = color;
}

