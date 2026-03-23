#ifndef DYNAMIC
#define DYNAMIC

#include "sequence.h"
#include <vector>

template <class key>
class dynamicSequence : public Sequence<key>
{
public:
  dynamicSequence(unsigned blocksize = 0) {}
  bool is_Full() const { return false; }
  bool search(const key &k) const override
  {
    for (const auto &i : array)
    {
      if (i == k)
      {
        return true;
      }
    }
    return false;
  }
  bool insert(const key &k) override
  {
    if (!search(k))
    {
      array.push_back(k);
      return true;
    }
    return false;
  }
  void print() const
  {
    std::cout << "[ ";
    for (const auto &i : array)
    {
      std::cout << i << " ";
    }
    std::cout << "]";
  }

private:
  std::vector<key> array;
};

#endif