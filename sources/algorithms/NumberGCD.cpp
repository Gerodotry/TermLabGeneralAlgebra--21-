#include "algorithms/NumberGCD.h"
#include "algorithms/NumberSubtraction.h"

Number NumberGCD::run(Number a, Number b, unsigned int modulo) {
    a.toField(modulo);
    b.toField(modulo);
    return gcd(a, b, modulo);
}

Number NumberGCD::gcd(Number& a, Number& b, unsigned int modulo) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    while (a != b) {
        if (a > b) {
            a = NumberSubtraction::run(a, b, modulo);
        }
        else {
            b = NumberSubtraction::run(b, a, modulo);
        }
    }
    a.toField(modulo);
    return a;
}
