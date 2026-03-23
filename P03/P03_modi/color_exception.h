#include <iostream>
#include <stdexcept>

class Color_Exception : public std::runtime_error {
  public:
  Color_Exception() : std::runtime_error("Este color no pertenece al rando de colores previsto para el mundo") {}
};