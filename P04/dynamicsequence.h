#ifndef DYNAMIC
#define DYNAMIC

#include "sequence.h"

template<class key> 
class dynamicSequence: public Sequence<key> {
  public:
    dynamicSequence() {}
    
    bool search (const key& k) const override {
      for (const auto& i : array) {
        if (i == k) { return true; }
      }
      return false;
    }

    bool insert (const key& k) override {
      if (!search(k)) {
        array.push_back(k);
        return true;
      }
      return false;
    }
    
  private:
    std::vector<key> array;
};

#endif