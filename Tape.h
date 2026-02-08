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

  Tape(int sizeX, int sizeY) // : tape_(sizeX, vector<bool>(sizeY, false)) { 
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
  const vector<vector<bool>>& get_tape() const { return tape_; }

  // Setter
  void set_color(bool color) { color_ = color; }

  void InfoCell(int posX, int posY) const {
    cout << "The cell is ";
    tape_[posX][posY] ? cout << "black" : cout << "white";
    cout << endl;
  }

  // Cambiar color de una celda
  void SetCell(int posX, int posY, bool color) {
    tape_[posX][posY] = color;
  }
};
