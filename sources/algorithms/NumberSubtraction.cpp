#include "algorithms/NumberSubtraction.h"

Number NumberSubtraction::run(Number a, Number b, Number modulo) {
    if (!modulo.isZero()) {
        a.toField(modulo);
        b.toField(modulo);
    }
    return subtract(a, b, modulo);
}

Number NumberSubtraction::subtract(Number& a, Number& b, Number& modulo) {
    Number result;
    if (a < b) {
        std::swap(a, b);
        result.isPositive = false;
    }

    result.digits.resize(a.digits.size());
    int borrow = 0;
    for (size_t i = 0; i < a.digits.size(); i++) {
        int digit = a.digits[i];
        if (i < b.digits.size()) {
            digit -= b.digits[i];
        }
        digit -= borrow;
        if (digit >= 0) {
            borrow = 0;
        } else {
            borrow = 1;
            digit += 10;
        }
        result.digits[i] = digit;
    }

    result.simplify();
    if (!modulo.isZero()) {
        result.toField(modulo);
    }
    return result;
}

