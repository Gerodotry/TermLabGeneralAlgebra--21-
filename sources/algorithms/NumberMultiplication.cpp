#include "algorithms/NumberMultiplication.h"

Number NumberMultiplication::run(Number a, Number b, Number modulo) {
    if (!modulo.isZero()) {
        a.toField(modulo);
        b.toField(modulo);
    } else {
        return a * b;
    }
    return multiply(a, b, modulo);
}

Number NumberMultiplication::multiply(Number &a, Number &b, Number& modulo) {
    Number product;
    std::size_t aSize = a.digits.size();
    std::size_t bSize = b.digits.size();
    product.digits.resize(aSize + bSize);
    for (std::size_t i = 0; i < aSize; i++) {
        unsigned int carry = 0;
        for (std::size_t j = 0; j < bSize; j++) {
            huge temp = huge(a.digits[i]) * huge(b.digits[j]) + huge(product.digits[i+j]) + huge(carry);
            product.digits[i+j] = temp % 10;
            carry = temp / 10;
        }
        if (carry > 0) {
            product.digits[i + bSize] += carry;
        }
    }

    product.simplify();

    if ((a.isPositive + b.isPositive) % 2) {
        product.isPositive = false;
    }

    if (!modulo.isZero()) {
        product.toField(modulo);
    }
    return product;
}
