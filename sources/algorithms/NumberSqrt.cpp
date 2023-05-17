//
// Created by Dmytro Khomych and Sergiy Polyukhovych on 08.05.2023.
//
#include "algorithms/NumberSqrt.h"
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberAddition.h"
#include <iostream>
#include <stdexcept>

Number NumberSqrt::run(Number a, unsigned int modulo) {
    if (modulo) {
        a.toField(modulo);
    }

    return sqrt(a, modulo);
}

Number NumberSqrt::sqrt(const Number &a, unsigned int modulo) {
    if (a < 0) {
        std::cout<<"Negative number";
    }
    if ((a == 0) or (a == 1)) {
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
