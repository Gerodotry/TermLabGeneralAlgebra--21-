#include "algorithms/Inverse.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberMultiplication.h"
// Created by mac on 08.05.2023.
//

Number Inverse::run(Number a, unsigned int modulo) {
    if (modulo) {
        a.toField(modulo);
    }
    return inverse(a, modulo);
}

Number Inverse::inverse(Number a, unsigned int modulo) {
    Number originalM = Number(modulo);
    Number x(0);
    Number y(1);
    Number lastX(1);
    Number lastY(0);


    while (modulo != 0) {
        Number quotient = a / Number(modulo);

        Number temp = Number(modulo);
        modulo = (a % Number(modulo)).get();
        a = temp;

        temp = x;
        x = NumberSubtraction::run(lastX, NumberMultiplication::run(quotient, x, 0), 0);
        lastX = temp;

        temp = y;
        y = NumberSubtraction::run(lastY, NumberMultiplication::run(quotient, y, 0), 0);
        lastY = temp;
    }
    if (a != 1) {
        return Number(-1);
    }

    if (!lastX.isPositive) {
        lastX.isPositive = true;
        lastX = NumberSubtraction::run(originalM, lastX, 0);
    }

    return lastX % originalM;
}