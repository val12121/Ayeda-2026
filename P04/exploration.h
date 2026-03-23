#ifndef EXPLORATION
#define EXPLORATION

template <typename key>
class ExplorationFunction {
  public:
    ~ExplorationFunction() {}
    virtual unsigned operator()(const key&, unsigned) const=0;
  private:
};
template <typename key> 
class FE_lineal : public ExplorationFunction<key> {
  public:
    FE_lineal() {} 
    unsigned operator()(const key& k, unsigned i) const override {
      return i; 
    }
};
template <typename key>
class FE_Quadratic : public ExplorationFunction<key> {
  public:
    FE_Quadratic() {}
    unsigned operator()(const key& k, unsigned i) const override {
      return i * i; // El salto es el cuadrado del intento
    }
};

template <typename key>
class FE_DoubleHash : public ExplorationFunction<key> {
  public:
    FE_DoubleHash(DispersionFunction<key>& fd) : fe_aux(fd) {}

    unsigned operator()(const key& k, unsigned i) const override {
      return i * fe_aux(k);
    }
  private:
    DispersionFunction<key>& fe_aux;
};

template <typename key>
class FE_Redispersion : public ExplorationFunction<key> {
  public:
    FE_Redispersion(DispersionFunction<key>& fd_aux) : fd_aux_(fd_aux) {}

    unsigned operator()(const key& k, unsigned i) const override {
      // Redispersión: el salto suele ser i veces una función secundaria
      return i * fd_aux_(k);
    }
  private:
    DispersionFunction<key>& fd_aux_;
};

#endif