#ifndef SEQUENCES_H
#define SEQUENCES_H

template <class Key>
class Sequence {
public:
//Los arguementos que luego habrá que pasar
    virtual unsigned size() const = 0;
    virtual Key operator[](const unsigned) const = 0;
    virtual Key& operator[](const unsigned) = 0;
    virtual ~Sequence() {}
};

template <class Key>
class staticSequence : public Sequence<Key> {
private:
    Key* data;
    unsigned seqSize;

public:
    staticSequence(unsigned size) : seqSize(size) {
        data = new Key[size];
    }

    unsigned size() const override {
        return seqSize;
    }

    Key operator[](const unsigned i) const override {
        return data[i];
    }

    Key& operator[](const unsigned i) override {
        return data[i];
    }

    ~staticSequence() {
        delete[] data;
    }
};

#endif // SEQUENCES_HPP