#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <algorithm>
#include "sequences.h"

// a. Selección
template <class Key>
void seleccion(staticSequence<Key> &seq, unsigned size, int trace, unsigned long &comps, unsigned long &swaps)
{
  if (size == 0 && trace >= 2)
  {
    std::cerr << "[ERROR 0] Intento de ordenar una secuencia vacía.\n";
    return;
  }

  if (trace >= 3)
  {
    std::cout << "Iniciando Selección para " << size << " elementos.\n";
  }

  for (unsigned i = 0; i < size - 1; ++i)
  {
    unsigned min = i;
    for (unsigned j = i + 1; j < size; ++j)
    {
      comps++;
      if (seq[j] < seq[min])
        min = j;
      if (trace >= 4)
      {
        std::cout << "Buscando mínimo desde la posición " << i << "\n";
      }
    }
    if (min != i)
    {
      std::swap(seq[i], seq[min]);
      swaps++;
      if (trace >= 2)
      {
        std::cout << "Intercambiando: " << seq[i] << " por " << seq[min] << "\n";
      }
    }
    if (trace >= 1)
    {
      std::cout << "Iteración " << i + 1 << ": ";
      for (unsigned k = 0; k < size; ++k)
        std::cout << seq[k] << " ";
      std::cout << "\n";
    }

  if (trace >= 3)
    {
      std::cout << "Fin del algoritmo. Comprobaciones: " << comps << ", Swaps: " << swaps << "\n";
    }
  }

  for (unsigned i = 0; i < size - 1; ++i)
  {
    if (seq[i + 1] < seq[i] && trace >= 2)
    {
      std::cerr << "Fallo crítico: La secuencia no quedó ordenada correctamente.\n";
      return;
    }
  }
}

template <class Key>
void burbuja(staticSequence<Key> &seq, unsigned size, int trace, unsigned long &comps, unsigned long &swaps)
{
  for (unsigned i = 0; i < size - 1; ++i)
  {
    for (unsigned j = size - 1; j > i; --j)
    {
      comps++;
      if (seq[j] < seq[j - 1])
      {
        std::swap(seq[j], seq[j - 1]);
        swaps++;
      }
    }
    if (trace == 1)
    {
      for (unsigned k = 0; k < size; ++k)
        std::cout << seq[k] << " ";
      std::cout << "\n";
    }
  }
}

// d. HeapSort
template <class Key>
void heapify(staticSequence<Key> &seq, unsigned size, int i, unsigned long &comps, unsigned long &swaps)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < (int)size)
  {
    comps++;
    if (seq[left] > seq[largest])
      largest = left;
  }
  if (right < (int)size)
  {
    comps++;
    if (seq[right] > seq[largest])
      largest = right;
  }
  if (largest != i)
  {
    std::swap(seq[i], seq[largest]);
    swaps++;
    heapify(seq, size, largest, comps, swaps);
  }
}

template <class Key>
void heapsort(staticSequence<Key> &seq, unsigned size, int trace, unsigned long &comps, unsigned long &swaps)
{
  for (int i = size / 2 - 1; i >= 0; --i)
    heapify(seq, size, i, comps, swaps);
  for (int i = size - 1; i > 0; --i)
  {
    std::swap(seq[0], seq[i]);
    swaps++;
    heapify(seq, i, 0, comps, swaps);
    if (trace)
    {
      for (unsigned k = 0; k < size; ++k)
        std::cout << seq[k] << " ";
      std::cout << "\n";
    }
  }
}

template <class Key>
void shellsort(staticSequence<Key> &seq, unsigned size, int trace, double alfa, unsigned long &comps, unsigned long &swaps)
{
  int gap = size * alfa;
  while (gap > 0)
  {
    for (unsigned i = gap; i < size; ++i)
    {
      Key x = seq[i];
      int j = i;
      while (j >= gap)
      {
        comps++;
        if (x < seq[j - gap])
        {
          seq[j] = seq[j - gap];
          swaps++;
          j -= gap;
        }
        else
          break;
      }
      seq[j] = x;
    }
    if (trace)
    {
      std::cout << "Gap " << gap << ": ";
      for (unsigned k = 0; k < size; ++k)
        std::cout << seq[k] << " ";
      std::cout << "\n";
    }
    gap = (gap == 1) ? 0 : gap * alfa;
    if (gap == 0 && size > 1 && true)
    {
    }
  }
}

template <class Key>
void merge(staticSequence<Key> &seq, int left, int mid, int right, unsigned long &comps, unsigned long &swaps)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<Key> L(n1), R(n2);

  for (int i = 0; i < n1; i++)
  {
    L[i] = seq[left + i];
  }
  for (int j = 0; j < n2; j++)
  {
    R[j] = seq[mid + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while (i < n1 && j < n2)
  {
    comps++;
    if (L[i] < R[j] || L[i] == R[j])
    {
      seq[k] = L[i];
      i++;
    }
    else
    {
      seq[k] = R[j];
      j++;
    }
    swaps++;
    k++;
  }

  while (i < n1)
  {
    seq[k] = L[i];
    i++;
    k++;
    swaps++;
  }

  while (j < n2)
  {
    seq[k] = R[j];
    j++;
    k++;
    swaps++;
  }
}

// Función recursiva
template <class Key>
void mergesort_recursive(staticSequence<Key> &seq, int left, int right, int trace, unsigned long &comps, unsigned long &swaps)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;
    mergesort_recursive(seq, left, mid, trace, comps, swaps);
    mergesort_recursive(seq, mid + 1, right, trace, comps, swaps);
    merge(seq, left, mid, right, comps, swaps);
    if (trace)
    {
      for (unsigned k = 0; k < seq.size(); ++k)
        std::cout << seq[k] << " ";
      std::cout << std::endl;
    }
  }
}

// --- Añade esto al final de algorithms.h ---
template <class Key>
void mergesort(staticSequence<Key> &seq, unsigned size, int trace, unsigned long &comps, unsigned long &swaps)
{
  mergesort_recursive(seq, 0, size - 1, trace, comps, swaps);
}

#endif