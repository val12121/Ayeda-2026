#ifndef DISPERSION
#define DISPERSION
#include <string>

template <typename key>
class DispersionFunction {
public:
    virtual ~DispersionFunction() {}
    virtual unsigned operator()(const key& k) const = 0;
};

template <typename key>
class FD_Module : public DispersionFunction<key> {
public:
    FD_Module(int tableSize) : tableSize_(tableSize) {}
    unsigned operator()(const key& k) const override {
        // Para strings, sumamos los valores ASCII de sus caracteres
        unsigned long sum = 0;
        for (char c : k) sum += static_cast<unsigned>(c);
        return (sum % tableSize_);
    }
private:
    int tableSize_;
};

template <typename key>
class FD_Sum : public DispersionFunction<key> {
public:
    FD_Sum(int tableSize) : tableSize_(tableSize) {}
    unsigned operator()(const key& k) const override {
        unsigned sum = 0;
        for (char c : k) sum += static_cast<unsigned>(c);
        return (sum % tableSize_);
    }
private:
    int tableSize_;
};

template <typename key> 
class FD_Rand : public DispersionFunction<key> {
public:
    FD_Rand(int tableSize) : tableSize_(tableSize) {}
    unsigned operator()(const key& k) const override {
        unsigned seed = 0;
        for (char c : k) seed += static_cast<unsigned>(c);
        srand(seed);
        return rand() % tableSize_;
    }
private:
    int tableSize_;
};
#endif