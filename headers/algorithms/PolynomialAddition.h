#ifndef LAB_POLYNOMIALADDITION_H
#define LAB_POLYNOMIALADDITION_H

#include "utils/RingPolynomial.h"
#include "NumberAddition.h"

class PolynomialAddition {
public:
    template<class T>
    static T run(T a, T b, Number modulo);
private:
    template<class T>
    static T add(const T& a, const T& b, Number& modulo);
};

template<class T>
T PolynomialAddition::run(T a, T b, Number modulo) {
    if (!modulo.isZero()) {
        a.toField(modulo);
        b.toField(modulo);
    }
    return add(a, b, modulo);
}

template<class T>
T PolynomialAddition::add(const T& a, const T& b, Number& modulo) {
    T sum;
    // Iterate over the terms of both polynomials and add them together
    int i = 0, j = 0;
    while (i < a.terms.size() && j < b.terms.size()) {
        Number aDegree = a.terms[i].getDegree(), bDegree = b.terms[j].getDegree();
        Number aCoefficient = a.terms[i].getCoefficient(), bCoefficient = b.terms[j].getCoefficient();
        if (aDegree == bDegree) {
            Number coefficientsSum = NumberAddition::run(aCoefficient, bCoefficient, 0);
            PolynomialTerm term({aDegree, coefficientsSum});
            sum.terms.push_back(term);
            ++i;
            ++j;
        }
        else if (aDegree > bDegree) {
            sum.terms.push_back(a.terms[i]);
            ++i;
        }
        else {
            sum.terms.push_back(b.terms[j]);
            ++j;
        }
    }
    // Add any remaining terms from the longer polynomial
    while (i < a.terms.size()) {
        sum.terms.push_back(a.terms[i]);
        i++;
    }
    while (j < b.terms.size()) {
        sum.terms.push_back(b.terms[j]);
        j++;
    }
    if (!modulo.isZero()) {
        sum.toField(modulo);
    }
    return sum;
}
#endif //LAB_POLYNOMIALADDITION_H
