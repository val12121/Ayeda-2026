#pragma once

#include "ab.h"

template <typename Key>
class ABE : public ArbolB<Key> {
  public:
    ABE() : ArbolB<Key>() {}
    ~ABE() {}

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
      if (clave == nodo->getDato()) {
        return false;
      }
      
      int tam_izq = this->TamRama(nodo->getIzdo());
      int tam_der = this->TamRama(nodo->getDcho());
      
      if (tam_izq > tam_der) {
        return insertarNodo(nodo->getDcho(), clave);
      } else {
        return insertarNodo(nodo->getIzdo(), clave);
      }
    }
    NodoB<Key>* buscarNodo(NodoB<Key>* nodo, const Key& clave) const {
      if (nodo == nullptr) {
        return nullptr;
      } if (nodo->getDato() == clave) {
        return nodo;
      }
      // Primero buscamos en la rama izquierda
      NodoB<Key>* encontrado = buscarNodo(nodo->getIzdo(), clave);
      
      // Si lo hemos encontrado en la izquierda
      if (encontrado != nullptr) {
        return encontrado;
      }
      //Si no estaba en al izq se va devolviendo lo que está a la derecha. 
      return buscarNodo(nodo->getDcho(), clave);
    }
};