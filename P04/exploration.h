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
    FE_lineal(std::vector<std::vector<key>> hash, unsigned blocksize) {
      hash_ = hash; 
      blocksize_ = blocksize;
      equality();
    }
    void equality() {
      aux_.resize(hash_.size());
      for (int i = 0; i < hash_.size(); i++) {
        hash_[i].resize(blocksize_);
      }
    }
  private:
    std::vector<std::vector<key>> hash_;
    std::vector<std::vector<bool>> aux_;
    unsigned blocksize_;
    bool overflowing;
};

#endif