﻿#include <algorithms/NumberSqrt.h>
#include <iostream>
#include <algorithms/NumberMultiplication.h>
#include "algorithms/Pollard.h"
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberAddition.h"
#include "algorithms/NumberGCD.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberRemainder.h"

std::vector<Number> Pollard::run(Number a) {

    return pollard_factorization(a);
}

std::vector<Number> Pollard::pollard_factorization(Number n) {

    std::vector<Number> factors;
    Number x = Number(2);
    Number y = Number(2);
    Number d = Number(1);

    while (d == 1) {
        x = NumberRemainder::run(NumberAddition::run(NumberMultiplication::run(x, x, 0), Number(1), 0), n, 0);

        y = NumberRemainder::run(NumberAddition::run(NumberMultiplication::run(y, y, 0), Number(1), 0), n, 0);
        y = NumberRemainder::run(NumberAddition::run(NumberMultiplication::run(y, y, 0), Number(1), 0), n, 0);

        std::cout << x.toString();
        std::cout << "\n";
        std::cout << y.toString();
        std::cout << "\n";

        d = NumberGCD::run(sub(x, y), n, UINT_MAX);
    }

    if (d == n)
        factors.push_back(Number(-1));
    else
        factors.push_back(n);

    return factors;
}

Number Pollard::sub(Number x, Number y) {
    if (!NumberSubtraction::run(x, y, 0).isPositive){
        return NumberSubtraction::run(y, x, 0);
    }else
        return NumberSubtraction::run(x, y, 0);
}
