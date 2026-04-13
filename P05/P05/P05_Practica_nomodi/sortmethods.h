#ifndef SORTMETHODS_H
#define SORTMETHODS_H

#include "sequences.h"
#include "algorithms.h"

template <class Key>
class SortMethod {
 protected:
    staticSequence<Key>& sequence_;
    unsigned size_;
    bool trace_;
    unsigned long comps_;
    unsigned long swaps_;
 public:
    SortMethod(staticSequence<Key>& seq, unsigned size, bool trace) 
        : sequence_(seq), size_(size), trace_(trace), comps_(0), swaps_(0) {}
    virtual ~SortMethod() {}
    virtual void Sort() = 0;
    unsigned long get_comps() { return comps_; }
    unsigned long get_swaps() { return swaps_; }
};

template <class Key>
class SelectionSort : public SortMethod<Key> {
 public:
    using SortMethod<Key>::SortMethod;
    void Sort() override { seleccion(this->sequence_, this->size_, this->trace_, this->comps_, this->swaps_); }
};

template <class Key>
class BubbleSort : public SortMethod<Key> {
 public:
    using SortMethod<Key>::SortMethod;
    void Sort() override { burbuja(this->sequence_, this->size_, this->trace_, this->comps_, this->swaps_); }
};

template <class Key>
class HeapSortMethod : public SortMethod<Key> {
 public:
    using SortMethod<Key>::SortMethod;
    void Sort() override { heapsort(this->sequence_, this->size_, this->trace_, this->comps_, this->swaps_); }
};

template <class Key>
class ShellSortMethod : public SortMethod<Key> {
 private:
    double alfa_;
 public:
    ShellSortMethod(staticSequence<Key>& seq, unsigned size, bool trace, double alfa) 
        : SortMethod<Key>(seq, size, trace), alfa_(alfa) {}
    void Sort() override { shellsort(this->sequence_, this->size_, this->trace_, alfa_, this->comps_, this->swaps_); }
};

template <class Key>
class MergeSortMethod : public SortMethod<Key> {
 public:
    using SortMethod<Key>::SortMethod;
    void Sort() override {
        mergesort(this->sequence_, this->size_, this->trace_, this->comps_, this->swaps_);
    }
};

#endif


