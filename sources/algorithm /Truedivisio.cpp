#include <stdexcept>
#include "algorithms/NumberDivision.h"
#include "algorithms/Truedivision.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberMultiplication.h"
#include "algorithms/Inverse.h"

Number Truedivision::run(Number a, Number b, Number modulo) {
    if (!modulo.isZero()) {
        a.toField(modulo);
        b.toField(modulo);
    }
    return tdivide(a, b, modulo);
}

Number Truedivision::tdivide( Number &a, Number &b, Number& modulo) {
    Number r(1);
    while (b > 0)
    {
        if (b % Number(2) == 1)
        {
            r = NumberMultiplication::run(r , a,0) % modulo;
        }
        a = NumberMultiplication::run(a ,a,0) % modulo;
        b = b / 2;
    }
    return r;
}
//
//Number inv = Inverse::run(b, modulo);
//Number result = NumberMultiplication::run( a ,inv, 0)% modulo;
//
