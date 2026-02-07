#include <iostream>
#include <vector>

using namespace std; 

class Tape {
  private:
    bool color_= false; // color == true ? black : white 
    int sizeX_ = 20;
    int sizeY_ = 20;
    vector<vector<bool>> tape_; 

  public:
    Tape() {};
    Tape(int sizeX, int sizeY) { 
      sizeX_ = sizeX; 
      sizeY_ = sizeY;

      tape_[sizeX][sizeY];
    }
  
    bool get_color() { return color_; };
    vector<vector<bool>> get_tape() { return tape_; };

    void set_color(bool color) { color_ = color; } 
    void InfoCell(int posX, int posY) {
      std::cout << "The cell is " << get_tape()[posX][posY] << endl;
    };
};