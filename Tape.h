#include <iostream>
#include <vector>

using namespace std;
class Tape {
 private:
  bool color_ = false;  // color == true ? black : white
  int sizeX_ = 20;
  int sizeY_ = 20;
  vector<vector<bool>> tape_;

 public:
  Tape() : tape_(sizeX_, vector<bool>(sizeY_, false)) {}

  Tape(int sizeX, int sizeY) 
  {
    sizeX_ = sizeX;
    sizeY_ = sizeY; 

    tape_.resize(sizeX);
    for (int i = 0; i < sizeX; ++i) {
      tape_[i].resize(sizeY, false);
    }
  }

  // Getters
  bool get_color() const { return color_; }
  int get_max_sizeX() const { return sizeX_; }
  int get_max_sizeY() const { return sizeY_; }
  const vector<vector<bool>>& get_tape() const { return tape_; } //Reference

  // Setter
  void set_color(bool color) { color_ = color; }

  void InfoCell(int posX, int posY);

  // Change Color of the Cell
  void SetCell(int posX, int posY, bool color);
};
