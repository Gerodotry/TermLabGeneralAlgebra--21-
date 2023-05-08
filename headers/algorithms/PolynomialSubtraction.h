#ifndef LAB_POLYNOMIALSUBTRACTION_H
#define LAB_POLYNOMIALSUBTRACTION_H

#include "utils/RingPolynomial.h"
#include "NumberSubtraction.h"

class PolynomialSubtraction {
public:
    template<class T>
    static T run(T a, T b, unsigned int modulo);

private:
    template<class T>
    static T subtract(const T& a, const T& b, unsigned int modulo);
};

template<class T>
T PolynomialSubtraction::run(T a, T b, unsigned int modulo) {
    if (modulo) {
        a.toField(modulo);
        b.toField(modulo);
    }
    return subtract(a, b, modulo);
}

template<class T>
T PolynomialSubtraction::subtract(const T& a, const T& b, unsigned int modulo) {
    T difference;
    // Iterate over the terms of both polynomials and subtract them
    int i = 0, j = 0;
    while (i < a.terms.size() && j < b.terms.size()) {
        Number aDegree = a.terms[i].getDegree(), bDegree = b.terms[j].getDegree();
        Number aCoefficient = a.terms[i].getCoefficient(), bCoefficient = b.terms[j].getCoefficient();
        if (aDegree == bDegree) {
            Number coefficientsDifference = NumberSubtraction::run(aCoefficient, bCoefficient, 0);
            PolynomialTerm term({aDegree, coefficientsDifference});
            difference.terms.push_back(term);
            ++i;
            ++j;
        }
        else if (aDegree > bDegree) {
            difference.terms.push_back(a.terms[i]);
            ++i;
        }
        else {
            difference.terms.push_back(b.terms[j]);
            ++j;
        }
    }
    // Add any remaining terms from the longer polynomial
    while (i < a.terms.size()) {
        difference.terms.push_back(a.terms[i]);
        i++;
    }
    while (j < b.terms.size()) {
        difference.terms.push_back(b.terms[j]);
        j++;
    }
    if (modulo) {
        difference.toField(modulo);
    }
    return difference;
}


#endif //LAB_POLYNOMIALSUBTRACTION_H
