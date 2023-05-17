#include "algorithms/Inverse.h"
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberMultiplication.h"
#include "algorithms/NumberAddition.h"
#include "algorithms/NumberRemainder.h"
// Created by mac on 08.05.2023.
//

Number Inverse::run(Number a, unsigned int modulo) {
    if (modulo) {
        a.toField(modulo);
    }

    return inverse(a, modulo);
}//Am I do something wrong
Number Inverse::inverse(Number a, unsigned int modulo) {
    Number m (modulo);
     Number x(0);
     Number y(1);
     Number gcd(modulo);
        if ( modulo == 1) return Number(0);
        while (a > 1) {
            Number q = NumberDivision::run(a,Number(modulo),0 );
            Number t(modulo);
            modulo = NumberRemainder::run(a, Number(modulo), 0).get();
            a = t;
            t = x;
            x = NumberSubtraction::run(y, NumberMultiplication::run( q,  x,  0), 0 );
            y = t;
        }
        if (y < 0) y = NumberAddition::run(y, gcd,1);
        return y;
}

