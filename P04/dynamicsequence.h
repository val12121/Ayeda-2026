#include "sequence.h"

template<class key> 
class dynamicSequence: public Sequence<key> {
  public:
    dynamicSequence(unsigned blocksize) : blocksize_(blocksize) {}
    
    bool search (const key& k) const override {
      for (const auto& i : array) {
        if (i == k) { return true; }
      }
      return false;
    }

    bool insert (const key& k) const override {
      if (!search(k)) {
        array.push_back(k);
        return true;
      }
      return false;
    }
  private:
    unsigned blocksize_;
    std::vector<key> array;
};