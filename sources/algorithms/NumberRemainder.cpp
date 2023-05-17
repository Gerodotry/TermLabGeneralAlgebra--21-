#include <stdexcept>
#include "algorithms/NumberRemainder.h"
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberMultiplication.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/Inverse.h"

Number NumberRemainder::run(Number a, Number b, Number modulo) {
    if (!modulo.isZero()) {
        a.toField(modulo);
        b.toField(modulo);
    } else {
        return a % b;
    }
    return remainder(a, b, modulo);
}

Number NumberRemainder::remainder(Number &a, Number &b, Number& modulo) {
    // Check for division by zero
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
/*
    // Bring the numbers into the finite field defined by m
    a = (a % modulo + modulo) % modulo;
    b = (b % modulo + modulo) % modulo;

    Number inv = Inverse::run(b, modulo);

    // Check if the modular inverse exists
    if (inv == -1) {
        throw std::runtime_error("Modular inverse does not exist");
    }

    // Calculate the remainder
    return (a * inv) % modulo;
    */

    // Bring the numbers into the finite field defined by m
    a = (a % modulo + modulo) % modulo;
    b = (b % modulo + modulo) % modulo;

    Number remainder = a;
    while (remainder >= b) {
        remainder = remainder - b;
    }

    return remainder;

}
