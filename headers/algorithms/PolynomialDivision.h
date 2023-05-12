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
    static T run(T dividend, T divisor, unsigned int modulo);
private:
    template<class T>
    static T divide(const T& dividend, T divisor, unsigned int modulo);
};

template<class T>
T PolynomialDivision::run(T dividend, T divisor, unsigned int modulo) {
    if (modulo) {
        dividend.toField(modulo);
        divisor.toField(modulo);
    }
    return divide(dividend, divisor, modulo);
}

template<class T>
T PolynomialDivision::divide(const T& dividend, T divisor, unsigned int modulo) {
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

        Number degree_diff = NumberSubtraction::run(remainder.terms.front().degree, divisor.terms.front().degree, 0);
        Number coeff_ratio = NumberDivision::run(remainder.terms.front().coefficient, divisor.terms.front().coefficient, 0);

        for (auto& term : divisor.terms) {
            term.coefficient = NumberMultiplication::run(term.coefficient, coeff_ratio, 0);
            term.degree = NumberAddition::run(term.degree, degree_diff, 0);
        }

        quotient.terms.push_back( { degree_diff, coeff_ratio } );
        remainder = PolynomialSubtraction::run(remainder, divisor, 0);

        for (auto& term : divisor.terms) {
            term.coefficient = NumberDivision::run(term.coefficient, coeff_ratio, 0);
            term.degree = NumberSubtraction::run(term.degree, degree_diff, 0);
        }
    }

    return quotient.terms.empty() ? T({ {0, 0} }) : quotient;
}

#endif // LAB_POLYNOMIALDIVISION_H