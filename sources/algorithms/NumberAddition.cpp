#include "algorithms/NumberAddition.h"

Number NumberAddition::run(Number a, Number b, Number modulo) {
    if (!modulo.isZero()) {
        a.toField(modulo);
        b.toField(modulo);
    } else {
        return a + b;
    }
    return add(a, b, modulo);
}

Number NumberAddition::add(Number& a, Number& b, Number& modulo) {
    Number result;
    std::size_t minSize = std::min(a.digits.size(), b.digits.size());
    bool carry = false;
    for (std::size_t i = 0; i < minSize; i++) {
        unsigned int v = a.digits[i] + b.digits[i] + carry;
        carry = v / 10;
        result.digits.emplace_back(v % 10);
    }
    Number longer = a.digits.size() > b.digits.size() ? a : b;
    std::size_t i = minSize;
    while (i < longer.digits.size()) {
        unsigned int v = longer[i] + carry;
        carry = v / 10;
        result.digits.emplace_back(v % 10);
        i++;
    }
    if (carry) {
        result.digits.emplace_back(1);
    }
    if (!modulo.isZero()) {
        result.toField(modulo);
    }
    return result;
}
