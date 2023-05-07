#include "algorithms/RingPolynomialMultiplication.h"
#include "algorithms/NumberMultiplication.h"

RingPolynomial RingPolynomialMultiplication::run(RingPolynomial a, RingPolynomial b, unsigned int modulo) {
    if (modulo) {
        a.toField(modulo);
        b.toField(modulo);
    }
    return multiply(a, b, modulo);
}

RingPolynomial RingPolynomialMultiplication::multiply(const RingPolynomial& a, const RingPolynomial& b, unsigned int modulo) {
    RingPolynomial product;
    // Multiply each term of a with each term of b and add the results to the product polynomial
    for (const auto& termA : a.terms) {
        for (const auto& termB : b.terms) {
            Number degree = NumberAddition::run(termA.getDegree(), termB.getDegree(), 0);
            Number coefficient = NumberMultiplication::run(termA.getCoefficient(), termB.getCoefficient(), 0);
            PolynomialTerm term({degree, coefficient});
            product.terms.push_back(term);
        }
    }
    // Combine like terms by adding coefficients of terms with the same degree
    product.sortByDegree();
    for (auto it = product.terms.begin(); it != product.terms.end(); ++it) {
        auto it2 = std::next(it);
        while (it2 != product.terms.end() && it2->getDegree() == it->getDegree()) {
            it->setCoefficient(NumberAddition::run(it->getCoefficient(), it2->getCoefficient(), 0));
            it2 = product.terms.erase(it2);
        }
    }
    if (modulo) {
        product.toField(modulo);
    }
    return product;
}

