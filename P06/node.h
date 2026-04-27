#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

template <typename Key>
class NodoB
{
protected:
  Key dato;
  NodoB<Key> *izdo;
  NodoB<Key> *dcho;

public:
  NodoB(const Key &dat, NodoB<Key> *izq = nullptr, NodoB<Key> *der = nullptr)
      : dato(dat), izdo(izq), dcho(der) {}

  ~NodoB() {}

  Key getDato() const { return dato; }
  NodoB<Key> *&getIzdo() { return izdo; }
  NodoB<Key> *&getDcho() { return dcho; }

  void setIzdo(NodoB<Key> *nodo) { izdo = nodo; }
  void setDcho(NodoB<Key> *nodo) { dcho = nodo; }
};