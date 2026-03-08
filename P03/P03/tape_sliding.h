#pragma once
#include "tape.h"
#include "ant_x.h"
#include "sliding_vector.h"

class TapeSliding : public Tape
{
public:
  TapeSliding(int sizex, int sizey) : matrix_(0, sizey - 1), Tape(sizex, sizey)
  {
    for (int i = 0; i < sizey; i++)
    {
      matrix_[i] = SlidingVector<int>(0, sizex - 1);
      for (int j = 0; j < sizex; j++)
      {
        matrix_[i][j] = 0; // O el color inicial que desees
      }
    }
  }

  bool switcher(Ant *ant) override;

  SlidingVector<SlidingVector<int>> get_matrix() { return matrix_; }

  int get_color(int x, int y) const override { return matrix_[y][x]; }
  // Getters de límites corregidos
  int get_min_sizeY() const override { return matrix_.getMin(); }
  int get_max_sizeY() const override { return matrix_.getMax(); }
  
  // Obtenemos el rango X 
  int get_min_sizeX() const override { return matrix_[matrix_.getMin()].getMin(); }
  int get_max_sizeX() const override { return matrix_[matrix_.getMin()].getMax(); }

  // Setters
  void SetCell(int posX, int posY, int color) override
  {
    matrix_[posY][posX] = color;
  }

  std::string show_color(int x, int y) override;
  // Para inicializar toda una fila a 0
  void set_row_0(SlidingVector<int>& vector)
  {
    for (int i = vector.getMin(); i <= vector.getMax(); i++)
    {
      vector[i] = 0;
    }
  }

  void InfoCell(int posX, int posY)
  {
    std::cout << matrix_[posX][posY] << std::endl;
  }

  friend std::ostream &operator<<(std::ostream &os, TapeSliding &tape)
  {
    for (int i = 0; i < tape.get_matrix().getMax(); i++)
    {
      for (int j = 0; j < tape.get_matrix()[i].getMax(); j++)
      {
        if (tape.get_matrix()[i][j] == 0)
        {
          os << BG_MAGENTA << "  " << RESET;
        }
        else if (tape.get_matrix()[i][j] == 1)
        {
          os << BG_WHITE << "  " << RESET;
        }
        else if (tape.get_matrix()[i][j] == 2)
        {
          os << BG_BLUE << "  " << RESET;
        }
        else if (tape.get_matrix()[i][j] == 3)
        {
          os << BG_BLACK << "  " << RESET;
        }
      }
      os << "\n";
    }
    return os;
  }

private:
  SlidingVector<SlidingVector<int>> matrix_;
};
