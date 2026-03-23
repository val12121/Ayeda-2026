#include "iostream"

template <typename key>
class Sequence {
  public:
    Sequence<key>() {}
    virtual bool Sequence<Key>::search(const Key& k) const = 0;
    virtual bool Sequence<Key>::insert(const Key& k) = 0;
  private:
};