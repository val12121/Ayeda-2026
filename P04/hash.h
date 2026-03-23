#ifndef HASH
#define HASH

#include <iostream>
#include "staticsequence.h"
#include "dynamicsequence.h"
#include "dispersion.h"
#include "exploration.h"

template <class key, class Container = staticSequence<key>>
class HashTable {
  public:
    HashTable(unsigned ts, DispersionFunction<key> &fd, ExplorationFunction<key> &fe, unsigned bs) 
        : fd_(fd), fe_(fe), tableSize_(ts), blockSize_(bs) {
      
      table = new Container*[tableSize_]; 
      for (unsigned i = 0; i < tableSize_; ++i) {
        table[i] = new Container(blockSize_); 
      }
    }

    // Destructor: Fundamental para liberar la memoria dinámica de Container**
    ~HashTable() {
      for (unsigned i = 0; i < tableSize_; ++i) {
        delete table[i];
      }
      delete[] table;
    }

    bool search(const key &k) const {
      unsigned i = 0;
      unsigned pos = fd_(k); 

      while (i < tableSize_) {
        // Aplicamos la función de exploración: g(k, i)
        unsigned current_pos = (pos + fe_(k, i)) % tableSize_;
        
        if (table[current_pos]->search(k)) {
          return true; 
        }

        // IMPORTANTE: En dispersión cerrada, si encontramos un hueco que NO está lleno,
        if (!table[current_pos]->is_Full()) {
          break;
        }
        i++;
      }
      return false;
    }

    bool insert(const key &k) {
      // Primero comprobamos si ya existe para evitar duplicados
      if (search(k)) return false; 
      
      unsigned i = 0;
      unsigned pos = fd_(k);

      while (i < tableSize_) {
        unsigned current_pos = (pos + fe_(k, i)) % tableSize_;
        
        // Intentamos insertar en el contenedor de esa posición
        if (table[current_pos]->insert(k)) {
          return true; 
        }
        // Si insert() devuelve false, el bloque está lleno, probamos el siguiente salto i
        i++;
      }
      return false; // Tabla o secuencia llena
    }

  private:
    DispersionFunction<key> &fd_;
    ExplorationFunction<key> &fe_;
    unsigned tableSize_;
    unsigned blockSize_;
    Container **table;
};

#endif