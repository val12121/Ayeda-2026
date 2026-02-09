#include <iostream>
#include <vector>
#include "colors.h"

using namespace std;
class Tape {
 private:
  bool color_ = false;  // color == true ? black : white
  int sizeX_ = 20;
  int sizeY_ = 20;
  vector<vector<bool>> tape_;

 public:
  Tape() : tape_(sizeX_, vector<bool>(sizeY_, false)) {
    //std::cout << tape_.size() << std::endl;
  }

  Tape(int sizeX, int sizeY) 
  {
    sizeX_ = sizeX;
    sizeY_ = sizeY; 

    tape_.resize(sizeX);
    for (int i = 0; i < sizeX; ++i) {
      tape_[i].resize(sizeY, false);
    }
  }

  friend std::ostream& operator<<(std::ostream& os, const Tape& tape) {
    for (int i = 0; i < tape.get_max_sizeX(); i++) {
      for (int j = 0; j < tape.get_max_sizeY(); j++) {
        if (tape.get_tape()[i][j] == false) {
          os << BG_BLUE << "  " << RESET;
        } else {
          os << BG_RED << "  " << RESET;
        }
      }
      os << "\n";
    }
    return os;
  }

  // Getters
  bool get_color( int x, int y ) const { return tape_[x][y]; }
  int get_max_sizeX() const { return sizeX_; }
  int get_max_sizeY() const { return sizeY_; }
  const vector<vector<bool>>& get_tape() const { return tape_; } //Reference

  // Setter
  void InfoCell(int posX, int posY);

  // Change Color of the Cell
  void SetCell(int posX, int posY, bool color);
};
