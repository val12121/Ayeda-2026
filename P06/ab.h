#pragma once

#include "node.h"

template <typename Key>
class ArbolB
{
protected:
  NodoB<Key> *raiz;

public:
  ArbolB() : raiz(NULL) {}
  ~ArbolB() { Podar(raiz); }
  void Podar(NodoB<Key> *&nodo)
  {
    if (nodo == NULL)
      return;
    Podar(nodo->getIzdo()); // Podar subarbol izquierdo
    Podar(nodo->getDcho()); // Podar subarbol derecho
    delete nodo;       // Eliminar nodo
    nodo = NULL;
  }

  NodoB<Key>* get_raiz() const {
    return raiz;
  }
  bool EsVacio(NodoB<Key> *nodo)
  {
    return nodo == NULL;
  }

  bool EsHoja(NodoB<Key> *nodo)
  {
    return !nodo->getDcho() && !nodo->getIzdo();
  }

  const int Tam() { return TamRama(raiz); }
  const int TamRama(NodoB<Key> *nodo)
  {
    if (nodo == NULL)
      return 0;
    return (1 + TamRama(nodo->getIzdo()) + TamRama(nodo->getDcho()));
  }
  const int Alt() { return AltN(raiz); } // Altura
  const int AltN(NodoB<Key> *nodo)
  {
    if (nodo == NULL)
      return 0;
    int alt_i = AltN(nodo->getIzdo());
    int alt_d = AltN(nodo->getDcho());

    if (alt_d > alt_i)
      return ++alt_d;
    else
      return ++alt_i;
  }

  virtual bool insertar(const Key &clave) = 0;
  virtual bool buscar(const Key &clave) const = 0;

  void InOrder() const {
    mostrarInOrder(raiz);
  }

  friend std::ostream& operator<<(std::ostream& os, const ArbolB<Key>& ab) {
    ab.mostrarPorNiveles(os);
    return os;
  }

protected:
  void mostrarInOrder(NodoB<Key> *nodo) const {
    if (nodo == nullptr)
      return;
    mostrarInOrder(nodo->getIzdo());
    std::cout << nodo->getDato() << " ";
    mostrarInOrder(nodo->getDcho());
  }

  void mostrarPorNiveles(std::ostream &os) const {
    if (raiz == nullptr) {
      os << "Nivel 0: [.]" << std::endl;
      return;
    }

    std::queue<NodoB<Key> *> cola;
    cola.push(raiz);
    int nivel = 0;

    while (!cola.empty()) {
      int nodosEnNivel = cola.size(); // Igualamos los nodos del nivel a aquellos restantes en la cola
      os << "Nivel " << nivel << ": ";

      for (int i = 0; i < nodosEnNivel; ++i) {
        NodoB<Key> *actual = cola.front();
        cola.pop();

        if (actual != nullptr) {  // Si el nodo actual esta lleno, pasamos a revisar su derecho e izquierdo
          os << "[" << actual->getDato() << "] "; // Mostramos el dato
          cola.push(actual->getIzdo());
          cola.push(actual->getDcho());
        } else
        {
          os << "[.] ";
        }
      }
      os << std::endl;
      ++nivel;
    }
  }
};