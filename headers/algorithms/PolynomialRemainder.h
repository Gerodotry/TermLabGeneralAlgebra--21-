//
// Created by Dklishch on 5/10/2023.
//

#ifndef LAB_POLYNOMIALREMAINDER_H
#define LAB_POLYNOMIALREMAINDER_H

#include <stdexcept>
#include "utils/Number.h"
#include "NumberSubtraction.h"
#include "NumberDivision.h"
#include "NumberMultiplication.h"
#include "PolynomialSubtraction.h"

class PolynomialRemainder {
public:
    template<class T>
    static T run(T dividend, T divisor, Number modulo);
private:
    template<class T>
    static T divide(const T& dividend, T divisor, Number& modulo);
};

template<class T>
T PolynomialRemainder::run(T dividend, T divisor, Number modulo) {
    if (!modulo.isZero()) {
        dividend.toField(modulo);
        divisor.toField(modulo);
    }
    return divide(dividend, divisor, modulo);
}

template<class T>
T PolynomialRemainder::divide(const T& dividend, T divisor, Number& modulo) {
    if (divisor.isZero()) {
        throw std::invalid_argument("Division by zero");
    }

    T quotient;
    T remainder(dividend);

    remainder.sortByDegree();
    divisor.sortByDegree();

    while (remainder.getDegree() >= divisor.getDegree()) {
        while (!remainder.terms.empty() && remainder.terms.front().coefficient.isZero()) {
            remainder.terms.erase(remainder.terms.begin());
        }

        if (remainder.terms.empty()) break;

        Number degree_diff = NumberSubtraction::run(remainder.terms.front().degree, divisor.terms.front().degree, 0);
        Number coeff_ratio = remainder.terms.front().coefficient / divisor.terms.front().coefficient;

        for (auto& term : divisor.terms) {
            term.coefficient = NumberMultiplication::run(term.coefficient, coeff_ratio, 0);
            term.degree = NumberAddition::run(term.degree, degree_diff, 0);
        }

        remainder = PolynomialSubtraction::run(remainder, divisor, 0);

        for (auto& term : divisor.terms) {
            term.coefficient = term.coefficient / coeff_ratio;
            term.degree = NumberSubtraction::run(term.degree, degree_diff, 0);
        }
    }

    return remainder.terms.empty() ? T({ {0, 0} }) : remainder;
}

#endif //LAB_POLYNOMIALREMAINDER_H
