#ifndef LAB_POLYNOMIALDIVISION_H
#define LAB_POLYNOMIALDIVISION_H

#include "utils/RingPolynomial.h"
#include "NumberDivision.h"
#include "NumberMultiplication.h"
#include "PolynomialMultiplication.h"
#include "PolynomialSubtraction.h"

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
    T quotient;
    T remainder = dividend;

    while (remainder.getDegree() >= divisor.getDegree()) {
        // Divide the leading term of the remainder by the leading term of the divisor
        const auto& leadingTermDividend = remainder.terms.front();
        const auto& leadingTermDivisor = divisor.terms.front();

        Number degreeDifference = NumberSubtraction::run(leadingTermDividend.getDegree(), leadingTermDivisor.getDegree(), 0);
        Number coefficientQuotient = NumberDivision::run(leadingTermDividend.getCoefficient(), leadingTermDivisor.getCoefficient(), modulo);

        PolynomialTerm term({degreeDifference, coefficientQuotient});
        quotient.terms.push_back(term);

        // Multiply the divisor by the term we just computed and subtract it from the remainder
        T product = PolynomialMultiplication::run(divisor, quotient, modulo);
        remainder = PolynomialSubtraction::run(remainder, product, modulo);
    }

    if (modulo) {
        quotient.toField(modulo);
        remainder.toField(modulo);
    }

    return quotient;
}

#endif // LAB_POLYNOMIALDIVISION_H
