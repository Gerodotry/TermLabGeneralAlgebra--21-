//
// Created by Dmytro Khomych and Sergiy Polyukhovych on 08.05.2023.
//
#include "algorithms/NumberSqrt.h"
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberAddition.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

Number NumberSqrt::run(Number a, unsigned int modulo) {
    if (modulo) {
        a.toField(modulo);
    }

    return sqrt(a, b, modulo);

Number NumberSqrt::sqrt(const Number &a, unsigned int modulo){
    NumberAddition na;
    NumberDivision nd;

    // If the input is not a number
    if (std::isnan(a)) {
        throw std::invalid_argument("Input is not a number.");
    }
    if (a < 0) {
        a = -a;
    }
    if (a == 1) {
        return 1;
    }

    double guess = nd.divide(a, 2);
    double prev_guess = nd.add(guess, 1);

    while (guess != prev_guess) {
        prev_guess = guess;
        guess = nd.divide((nd.divide(nd.add(guess, a), guess)), 2);
    }

    return guess;
};
