#include "algorithms/NumberAddition.h"

Number NumberAddition::run(Number a, Number b, unsigned int modulo) {
    a.toField(modulo);
    b.toField(modulo);
    return add(a, b, modulo);
}

Number NumberAddition::add(const Number& a, const Number& b, unsigned int modulo) {
    unsigned int numeral = modulo ? modulo : 10;
    Number result;
    std::size_t minSize = std::min(a.digits.size(), b.digits.size());
    bool carry = false;
    for (std::size_t i = 0; i < minSize; i++) {
        unsigned int v = a.digits[i] + b.digits[i] + carry;
        carry = v >= numeral;
        result.digits.emplace_back(v - numeral * carry);
    }
    Number longer = a.digits.size() > b.digits.size() ? a : b;
    std::size_t i = minSize;
    while (i < longer.digits.size()) {
        unsigned int v = longer[i] + carry;
        carry = v >= numeral;
        result.digits.emplace_back(v - numeral * carry);
        i++;
    }
    if (carry) {
        result.digits.emplace_back(1);
    }
    if (modulo) {
        result.toField(modulo);
    }
    return result;
}
