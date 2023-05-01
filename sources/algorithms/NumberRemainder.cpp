#include "algorithms/NumberRemainder.h"
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberMultiplication.h"
#include "algorithms/NumberSubtraction.h"

Number NumberRemainder::run(Number a, Number b, unsigned int modulo) {
    a.toField(modulo);
    b.toField(modulo);
    return remainder(a, b, modulo);
}

Number NumberRemainder::remainder(const Number &a, const Number &b, unsigned int modulo) {
    // Check for division by zero
    if (b.isZero()) {
        throw std::invalid_argument("Division by zero");
    }
    // Divide a by b and return the remainder
    Number quotient, remainder;
    quotient = NumberDivision::run(a, b, modulo);
    remainder = NumberMultiplication::run(quotient, b, modulo);
    remainder = NumberSubtraction::run(a, remainder, modulo);
    remainder.toField(modulo);
    return remainder;
}
