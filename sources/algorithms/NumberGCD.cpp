#include "algorithms/NumberGCD.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberRemainder.h"

Number NumberGCD::run(Number a, Number b, unsigned int modulo) {
    if (modulo) {
        a.toField(modulo);
        b.toField(modulo);
    }
    return gcd(a, b, modulo);
}

Number NumberGCD::gcd(Number& a, Number& b, unsigned int modulo) {
    if (a == 0) return b;
    if (b == 0) return a;

    while (a != b && !a.isZero() && !b.isZero()) {
        if (a > b) {
            a = NumberRemainder::run(a, b, modulo);
        }
        else {
            b = NumberRemainder::run(b, a, modulo);
        }
    }
    if (modulo) {
        if (a.isZero()) {
            b.toField(modulo);
        } else {
            a.toField(modulo);
        }
    }
    return a.isZero() ? b : a;
}
