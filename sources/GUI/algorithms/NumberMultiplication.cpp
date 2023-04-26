#include "../../headers/algorithms/NumberMultiplication.h"

Number NumberMultiplication::run(Number a, Number b, unsigned int modulo) {
    a.toField(modulo);
    b.toField(modulo);
    return multiply(a, b, modulo);
}

Number NumberMultiplication::multiply(const Number &a, const Number &b, unsigned int modulo) {
    Number product;
    std::size_t aSize = a.digits.size();
    std::size_t bSize = b.digits.size();
    product.digits.resize(aSize + bSize);
    for (std::size_t i = 0; i < aSize; i++) {
        unsigned int carry = 0;
        for (std::size_t j = 0; j < bSize; j++) {
            huge temp = huge(a.digits[i]) * huge(b.digits[j]) + huge(product.digits[i+j]) + huge(carry);
            product.digits[i+j] = temp % modulo;
            carry = temp / modulo;
        }
        if (carry > 0) {
            product.digits[i + bSize] += carry;
        }
    }

    product.simplify();
    product.toField(modulo);
    return product;
}
