//
// Created by Dmytro Khomych and Sergiy Polyukhovych on 08.05.2023.
//
#include "algorithms/NumberSqrt.h"
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberAddition.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

Number NumberSqrt::run(Number a, Number modulo) {
    if (!modulo.isZero()) {
        a.toField(modulo);
    }

    return sqrt(a, modulo);
}

Number NumberSqrt::sqrt(Number &a, Number &modulo) {
    if (!a.isPositive) {
        throw std::invalid_argument("Division by zero");
    }
    if (a == 1) {
        return Number(1);
    }

    Number guess = NumberDivision::run(a, Number(2), modulo);
    Number prev_guess = NumberAddition::run(guess, Number(1), modulo);

    while (guess != prev_guess) {
        prev_guess = guess;
        guess = NumberDivision::run(NumberDivision::run(NumberAddition::run(guess, a, modulo), guess, modulo), Number(2), modulo);
    }

    return guess;
};
