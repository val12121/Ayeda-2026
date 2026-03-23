#include <iostream>

template <typename key>
class DispersionFunction {
  public:
    ~DispersionFunction() {};
    virtual unsigned DispersionFunction<Key>::operator()(const Key&) const = 0;
};

template <typename key>
class FD_Module : public DispersionFunction<Key> {
  public:
    FD_Module(int tableSize) : tableSize_(tableSize) {}
    
    unsigned operator()(const key& k) const override {
      return (static_cast<long>k % tableSize);
    }
  private:
    int tableSize_;
};

template <typename key>
class FD_Sum : public DispersionFunction<Key> {
  public:
    FD_Sum(int tableSize) : tableSize_(tableSize) {}
    
    unsigned operator()(const key& k) const override {
      std::string keykey = std::to_string(static_cast(long)k);
      int sum;
      for (int i = 0; i < keykey.size(); i++) {
        sum += keykey[i];
      }
      return (sum % tableSize)
    }
  private:
    int tableSize_;
};

template <typename key> 
class FD_Rand : public DispersionFunction<Key> {
  public:
    FD_Rand(int tableSize) : tableSize_(tableSize) {}
    unsigned operator()(const key& k) const override {
      srand(static_cast<long>(k));
      return rand() % tableSize_;
    }
  private:
    int tableSize_;
};

