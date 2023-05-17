#ifndef LAB_POLYNOMIALDIVISION_H
#define LAB_POLYNOMIALDIVISION_H

#include "utils/RingPolynomial.h"
#include "NumberDivision.h"
#include "NumberMultiplication.h"
#include "PolynomialMultiplication.h"
#include "PolynomialSubtraction.h"
#include <stdexcept>

class PolynomialDivision {
public:
    template<class T>
    static T run(T dividend, T divisor, Number modulo);
private:
    template<class T>
    static T divide(T& dividend, T divisor, Number& modulo);
};

template<class T>
T PolynomialDivision::run(T dividend, T divisor, Number modulo) {
    if (!modulo.isZero()) {
        dividend.toField(modulo);
        divisor.toField(modulo);
    }
    return divide(dividend, divisor, modulo);
}

template<class T>
T PolynomialDivision::divide(T& dividend, T divisor, Number& modulo) {
    if (divisor.isZero()) {
        throw std::invalid_argument("Division by zero");
    }

    T quotient;
    T remainder(dividend);

    remainder.sortByDegree();
    divisor.sortByDegree();

    dividend.dropZeroes();
    divisor.dropZeroes();

    while (remainder.getDegree() >= divisor.getDegree()) {
        while (!remainder.terms.empty() && remainder.terms.front().coefficient.isZero()) {
            remainder.terms.erase(remainder.terms.begin());
        }

        if (remainder.terms.empty()) break;

        Number degree_diff = remainder.terms.front().degree - divisor.terms.front().degree;
        Number coeff_ratio = remainder.terms.front().coefficient / divisor.terms.front().coefficient;

        if (degree_diff.isZero() && coeff_ratio.isZero()) break;

        for (auto& term : divisor.terms) {
            term.coefficient = term.coefficient * coeff_ratio;
            term.degree = term.degree + degree_diff;
        }

        quotient.terms.push_back( { degree_diff, coeff_ratio } );
        remainder = PolynomialSubtraction::run(remainder, divisor, 0);

        for (auto& term : divisor.terms) {
            term.coefficient = term.coefficient / coeff_ratio;
            term.degree = term.degree - degree_diff;
        }
    }

    return quotient.terms.empty() ? T({ {0, 0} }) : quotient;
}

#endif // LAB_POLYNOMIALDIVISION_H
