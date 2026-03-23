#pragma once
#include <vector>
#include <stdexcept>

// Excepción personalizada
class SVException : public std::runtime_error
{
public:
  SVException() : std::runtime_error("Fuera de rango en SlidingVector") {}
};

template <typename T>
class SlidingVector
{
public:
  SlidingVector() : indexMin_(0), indexMax_(-1) {}
  SlidingVector(int min, int max) : indexMin_(min), indexMax_(max)
  {
    v_.resize(max - min + 1); // Tamaño total necesario
  }

  T &operator[](int index)
  {
    if (index < indexMin_ || index > indexMax_)
    {
      throw SVException(); // Colisión con la frontera
    }
    return v_[index - indexMin_];
  }

  const T &operator[](int index) const
  {
    if (index < indexMin_ || index > indexMax_)
    {
      throw SVException();
    }
    return v_[index - indexMin_];
  }

  // Métodos para expandir la cinta
  void push_back(const T &val)
  {
    v_.push_back(val);
    indexMax_++; // Aumenta el rango por el final
  }

  void push_front(const T &val)
  {
    v_.insert(v_.begin(), val);
    indexMin_--; // El nuevo elemento tiene un índice negativo
  }

  int getMin() const { return indexMin_; }
  int getMax() const { return indexMax_; }

private:
  std::vector<T> v_;
  int indexMin_;
  int indexMax_;
};