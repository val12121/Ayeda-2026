#ifndef NIF_H
#define NIF_H

#include <iostream>

class nif { //Valor númerico
private:
    int value;

public:
    nif(int v = 0) : value(v) {}

    bool operator<(const nif& other) const {
        return value < other.value;
    }

    bool operator>(const nif& other) const {
        return value > other.value;
    }

    bool operator==(const nif& other) const {
        return value == other.value;
    }

    friend std::ostream& operator<<(std::ostream& os, const nif& n) {
        os << n.value;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, nif& n) {
        is >> n.value;
        return is;
    }
};

#endif // NIF_HPP