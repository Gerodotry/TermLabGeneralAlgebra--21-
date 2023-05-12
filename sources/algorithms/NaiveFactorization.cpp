﻿#include <algorithms/NumberGCD.h>
#include <algorithms/NumberRemainder.h>
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberAddition.h"
#include "algorithms/NaiveFactorization.h"

std::vector<Number> NaiveFactorization::run(Number a) {
    return naive_factorization(a);
}

std::vector<Number> NaiveFactorization::naive_factorization(Number& n) {
    std::vector<Number> factors;

    for (Number i = Number(2); i <= NumberDivision::run(n, i, 0); i = NumberAddition::run(i, Number(1), 0)) {
        while (NumberRemainder::run(n, i, 0).isZero()) {
            factors.push_back(i);
            n = NumberDivision::run(n, i, 0);
        }
    }

    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}



