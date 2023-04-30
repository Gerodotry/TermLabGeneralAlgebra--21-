#include "algorithms/PolynomialAddition.h"
#include "algorithms/NumberAddition.h"

Polynomial PolynomialAddition::run(Polynomial a, Polynomial b, unsigned int modulo) {
    a.toField(modulo);
    b.toField(modulo);
    return add(a, b, modulo);
}

Polynomial PolynomialAddition::add(const Polynomial& a, const Polynomial& b, const unsigned int& modulo) {
    Polynomial sum;
    // Iterate over the terms of both polynomials and add them together
    int i = 0, j = 0;
    while (i < a.terms.size() && j < b.terms.size()) {
        Number aDegree = a.terms[i].getDegree(), bDegree = b.terms[i].getDegree();
        Number aCoefficient = a.terms[i].getCoefficient(), bCoefficient = b.terms[i].getCoefficient();
        if (aDegree == bDegree) {
            Number coefficientsSum = NumberAddition::run(aCoefficient, bCoefficient, modulo);
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
    sum.toField(modulo);
    return sum;
}
