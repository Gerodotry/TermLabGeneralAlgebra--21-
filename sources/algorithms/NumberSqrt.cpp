//
// Created by Dmytro Khomych and Sergiy Polyukhovych on 08.05.2023.
//
#include "algorithms/NumberSqrt.h"
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberAddition.h"
#include <iostream>
#include <stdexcept>

Number NumberSqrt::run(Number a, Number modulo) {
    if (!modulo.isZero()) {
        a.toField(modulo);
    }

    return sqrt(a, modulo);
}

Number NumberSqrt::sqrt(Number &a, Number &modulo) {
    if (!a.isPositive) {
        std::cout<<"Negative number";
    }
    if (a.isZero() or (a == 1)) {
        return Number(1);
    }

    Number x = a;
    Number y = Number(1);

    while (x > y) {
        x = NumberDivision::run(NumberAddition::run(x, y, modulo), Number(2), modulo);
        y = NumberDivision::run(a, x, modulo);
    }

    return x;
}
