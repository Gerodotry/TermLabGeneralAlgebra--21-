#include "algorithms/NumberSubtraction.h"

Number NumberSubtraction::run(Number a, Number b, unsigned int modulo) {
    a.toField(modulo);
    b.toField(modulo);
    return subtract(a, b, modulo);
}

Number NumberSubtraction::subtract(Number& a, Number& b, unsigned int modulo) {
    if (a < b) {
        std::swap(a, b);
    }
    const std::vector<unsigned int>& big = a.digits, small = b.digits;
    bool borrow = false;
    Number difference;
    for (unsigned int i = 0; i < small.size(); i++) {
        unsigned int v = big[i] - small[i] - borrow;
        borrow = v >= modulo;
        difference.digits.push_back(v + modulo * borrow);
    }
    for (unsigned int i = small.size(); i < big.size(); i++) {
        unsigned int v = big[i] - borrow;
        borrow = v >= modulo;
        difference.digits.push_back(v + modulo * borrow);
    }
    difference.toField(modulo);
    return difference;
}
