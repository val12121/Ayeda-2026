#include "sequence.h"

template <typename key>
class staticSequence : public Sequence<key>{
  public:
    staticSequence(unsigned blocksize) : blocksize_(blocksize) {}
    bool is_Full () {
      array >= 0 ? true : false: 
    }

    bool search (const key& k) const override {
      for (const auto& i : array) {
        if (i == k) return true;
      }
      else return false;
    }

    bool insert (const key& k) const override {
      if (is_Full()) return false;
      if (!search(k)) {
        array.push_back(k);
        return true:
      }
      return true; //Da un error si no lo pongo
    }
  private:
    unsigned blocksize_;
    std::vector<key> array;
};