#include <iostream>
#include "staticsequence.h"
#include "dynamicsequence.h"
#include "dispersion.h"
#include "exploration.h"

template <class key, class Container = staticSequence<key>> 
class HashTable {
  public:
    HashTable<Key,Container>(unsigned, DispersionFunction<Key>& fd, ExplorationFunction<Key>&,unsigned fe) {
      fd_ = new DispersionFunction(fd);
      fe_ = new ExplorationFunction(fe);
    }
  private:
    DispersionFunction<Key> fd_;
    ExplorationFunction<Key> fe_;
    key tableSize_;
    key blockSize_;
};
