#include "algorithms/NumberAddition.h"

Number NumberAddition::run(Number a, Number b, unsigned int modulo) {
    a.toField(modulo);
    b.toField(modulo);
    return add(a, b, modulo);
}

Number NumberAddition::add(Number a, Number b, unsigned int modulo) {
    Number result;
    std::size_t minSize = std::min(a.digits.size(), b.digits.size());
    bool carry = false;
    for (std::size_t i = 0; i < minSize; i++) {
        unsigned int v = a[i] + b[i] + carry;
        carry = v >= modulo;
        result.digits.emplace_back(v - modulo * carry);
    }
    Number longer = a.digits.size() > b.digits.size() ? a : b;
    std::size_t i = minSize;
    while (i < longer.digits.size()) {
        unsigned int v = longer[i] + carry;
        carry = v >= modulo;
        result.digits.emplace_back(v - modulo * carry);
        i++;
    }
    if (carry) {
        result.digits.emplace_back(1);
    }
    result.toField(modulo);
    return result;
}
