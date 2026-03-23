#ifndef STATIC
#define STATIC

#include "sequence.h"

template <typename key>
class staticSequence : public Sequence<key>
{
public:
  staticSequence(unsigned blocksize) : blocksize_(blocksize) {}
  bool is_Full()
  {
    return array.size() >= blocksize_;
  }
  bool search(const key &k) const override
  {
    for (const auto &i : array)
    {
      if (i == k)
        return true;
    }
    return false;
  }
  bool insert(const key &k) override
  {
    if (is_Full())
      return false;
    if (!search(k))
    {
      array.push_back(k);
      return true;
    }
    return true; // Da un warning
  }
  void print() const
  {
    std::cout << "[";
    for (unsigned i = 0; i < array.size(); ++i) {
      std::cout << array[i] << (i < array.size() - 1 ? ", " : "");
    }
    for (unsigned i = array.size(); i < blocksize_; ++i) {
      std::cout << " . " << (i < blocksize_ - 1 ? ", " : "");
    }
    std::cout << "]";
  }

private:
  unsigned blocksize_;
  std::vector<key> array;
};

#endif