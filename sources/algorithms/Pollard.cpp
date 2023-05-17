#include <algorithms/NumberSqrt.h>
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

    if (!n.isPositive){
        factors.push_back(n);
        return factors;
    }

    while (d == 1) {
        x = ((x * x) + Number(1)) % n;
        y = ((y * y) + Number(1)) % n;
        y = ((y * y) + Number(1)) % n;

        d = NumberGCD::run(sub(x, y), n, UINT_MAX);
    }

    if (d != n) {
        factors.push_back(d);
        std::vector<Number> remainingFactors = pollard_factorization(n / d);
        factors.insert(factors.end(), remainingFactors.begin(), remainingFactors.end());
    } else {
        factors.push_back(n);
    }

    return factors;
}

Number Pollard::sub(Number x, Number y) {
    if (!(x - y).isPositive){
        return y - x;
    }else
        return x - y;
}
