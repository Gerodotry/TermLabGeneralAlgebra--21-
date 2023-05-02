#include "algorithms/NumberSubtraction.h"

Number NumberSubtraction::run(Number a, Number b, unsigned int modulo) {
    a.toField(modulo);
    b.toField(modulo);
    return subtract(a, b, modulo);
}

Number NumberSubtraction::subtract(Number& a, Number& b, unsigned int modulo) {
    Number result;
    if (a < b) {
        std::swap(a, b);
        result.isPositive = false;
    }
    result.digits.resize(a.digits.size());
    unsigned int borrow = 0;
    for (size_t i = 0; i < a.digits.size(); i++) {
        unsigned int digit = a.digits[i];
        if (i < b.digits.size()) {
            digit -= b.digits[i];
        }
        digit -= borrow;
        borrow = 0;
        result.digits[i] = digit;
    }
    result.simplify();
    result.toField(modulo);
    return result;
}

