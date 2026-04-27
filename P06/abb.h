#pragma once

#include "ab.h"

template <typename Key>
class ABB : public ArbolB<Key> {
  public:
    ABB() : ArbolB<Key>() {}
    ~ABB() {}

    bool insertar(const Key &clave) override {
      return insertarNodo(this->raiz, clave);
    }

    bool buscar(const Key &clave) const override {
      return buscarNodo(this->raiz, clave) != nullptr;
    }

  protected:

    bool insertarNodo(NodoB<Key>*& nodo, const Key& clave) {
      if (nodo == nullptr) {
        nodo = new NodoB<Key>(clave);
        return true;
      }
      else if (clave == nodo->getDato()) {
        return false;
      }
      else if (clave < nodo->getDato()) {
        return insertarNodo(nodo->getIzdo(), clave);
      } else {
        return insertarNodo(nodo->getDcho(), clave);
      }
    }

    NodoB<Key> *buscarNodo(NodoB<Key>* nodo, const Key& clave) const {
      if (nodo == nullptr) {
        return nullptr;
      }
      if (nodo->getDato() == clave) return nodo;
      if (nodo->getDato() > clave) {
        return buscarNodo(nodo->getIzdo(), clave);
      } else {
        return buscarNodo(nodo->getDcho(), clave);
      }
    }
};