#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberAddition.h"

Number NumberSubtraction::run(Number a, Number b, Number modulo) {
    if (!modulo.isZero()) {
        a.toField(modulo);
        b.toField(modulo);
    } else {
        return a - b;
    }
    return subtract(a, b, modulo);
}

Number NumberSubtraction::subtract(Number& a, Number& b, Number& modulo) {
    Number result;

    if (a.isPositive && !b.isPositive) {
        b.isPositive = true;
        return NumberAddition::run(a, b, modulo);
    }

    if (!a.isPositive && b.isPositive) {
        a.isPositive = true;
        Number result = NumberAddition::run(a, b, modulo);
        result.isPositive = false;
        return result;
    }

    if (!a.isPositive && !b.isPositive) {
        std::swap(a, b);
        a.isPositive = true;
        b.isPositive = true;
    }

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

