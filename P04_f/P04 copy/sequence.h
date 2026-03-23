#ifndef SEQUENCE
#define SEQUENCE
#include "iostream"

template <typename key>
class Sequence {
  public:
    Sequence<key>() {}
    virtual bool search(const key& k) const = 0;
    virtual bool insert(const key& k) = 0;
  private:
};

#endif