#ifndef STATIC
#define STATIC

#include "sequence.h"

template <typename key>
class staticSequence : public Sequence<key>{
  public:
    staticSequence(unsigned blocksize) : blocksize_(blocksize) {}
    bool is_Full () {
      return array.size() >= blocksize_;
    }    
    bool search (const key& k) const override {
      for (const auto& i : array) {
        if (i == k) return true;
      }
      return false;
    }
    bool insert (const key& k) override {
      if (is_Full()) return false;
      if (!search(k)) {
        array.push_back(k);
        return true;
      }
      return true; //Da un warning
    }
  private:
    unsigned blocksize_;
    std::vector<key> array;
};

#endif