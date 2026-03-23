#include "tape_sliding.h"

bool TapeSliding::switcher(Ant *ant)
{
  int minX = get_min_sizeX();
  int maxX = get_max_sizeX();
  if (ant->getx() < minX) {
    for (int i = matrix_.getMin(); i <= matrix_.getMax(); i++) {
      matrix_[i].push_front(0);
    }
  } 
  if (ant->getx() > maxX) {
    for (int i = matrix_.getMin(); i <= matrix_.getMax(); i++) {
      matrix_[i].push_back(0);
    }
  }

  int currentMinX = get_min_sizeX();
  int currentMaxX = get_max_sizeX();

  if (ant->gety() < matrix_.getMin())
  {
    SlidingVector<int> new_row(currentMinX, currentMaxX);
    set_row_0(new_row);
    matrix_.push_front(new_row);
  }
  if (ant->gety() > matrix_.getMax())
  {
    SlidingVector<int> new_row(currentMinX, currentMaxX);
    set_row_0(new_row);
    matrix_.push_back(new_row);
  }
  return false;
}

std::string TapeSliding::show_color(int x, int y) {
  int color = matrix_[y][x]; // matrix_[fila][columna]
  switch (color) {
    case 0: return BG_MAGENTA;
    case 1: return BG_WHITE;
    case 2: return BG_BLUE;
    case 3: return BG_BLACK;
    default: return RESET;
  }
}