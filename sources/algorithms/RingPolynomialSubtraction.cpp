#include "algorithms/RingPolynomialSubtraction.h"
#include "algorithms/NumberSubtraction.h"

RingPolynomial RingPolynomialSubtraction::run(RingPolynomial a, RingPolynomial b, unsigned int modulo) {
    a.toField(modulo);
    b.toField(modulo);
    return subtract(a, b, modulo);
}

RingPolynomial RingPolynomialSubtraction::subtract(const RingPolynomial& a, const RingPolynomial& b, unsigned int modulo) {
    RingPolynomial difference;
    // Iterate over the terms of both polynomials and subtract them
    int i = 0, j = 0;
    while (i < a.terms.size() && j < b.terms.size()) {
        Number aDegree = a.terms[i].getDegree(), bDegree = b.terms[i].getDegree();
        Number aCoefficient = a.terms[i].getCoefficient(), bCoefficient = b.terms[i].getCoefficient();
        if (aDegree == bDegree) {
            Number coefficientsDifference = NumberSubtraction::run(aCoefficient, bCoefficient, modulo);
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
    difference.toField(modulo);
    return difference;
}
