#include <stdexcept>
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberMultiplication.h"
#include "algorithms/Inverse.h"

Number NumberDivision::run(Number a, Number b, Number modulo) {
    if (!modulo.isZero()) {
        a.toField(modulo);
        b.toField(modulo);
    } else {
        return a / b;
    }
    return divide(a, b, modulo);
}

Number NumberDivision::divide(Number &a, Number &b, Number &modulo) {
    if (b.isZero()) {
        throw std::invalid_argument("Division by zero");
    }
    Number inv = Inverse::run(b, modulo);
    return NumberMultiplication::run(a, inv, modulo);
}
