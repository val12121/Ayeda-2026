#ifndef HASH
#define HASH

#include <iostream>
#include "staticsequence.h"
#include "dynamicsequence.h"
#include "dispersion.h"
#include "exploration.h"

template <class key, class Container = staticSequence<key>>
class HashTable
{
public:
  HashTable<key, Container>(unsigned ts, DispersionFunction<key> &fd, ExplorationFunction<key> &, unsigned fe, unsigned bs) : fd_(fd), fe_(fe), tableSize_(ts), blockSize_(bs)
  {
    table = new Container *[tableSize_]; //Vector de vectores
    for (unsigned i = 0; i < tableSize_; ++i) {
      table[i] = new Container(blockSize_); // Inicializamos cada secuencia
    }
  }

private:
  DispersionFunction<key> &fd_;
  ExplorationFunction<key> &fe_;
  unsigned tableSize_;
  unsigned blockSize_;
  Container **table;
};

#endif