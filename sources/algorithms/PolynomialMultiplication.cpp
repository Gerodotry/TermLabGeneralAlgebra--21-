#include "algorithms/PolynomialMultiplication.h"
#include "algorithms/NumberMultiplication.h"

Polynomial PolynomialMultiplication::run(Polynomial a, Polynomial b, unsigned int modulo) {
    a.toField(modulo);
    b.toField(modulo);
    return multiply(a, b, modulo);
}

Polynomial PolynomialMultiplication::multiply(const Polynomial& a, const Polynomial& b, unsigned int modulo) {
    Polynomial product;
    // Multiply each term of a with each term of b and add the results to the product polynomial
    for (const auto& termA : a.terms) {
        for (const auto& termB : b.terms) {
            Number degree = NumberAddition::run(termA.getDegree(), termB.getDegree(), modulo);
            Number coefficient = NumberMultiplication::run(termA.getCoefficient(), termB.getCoefficient(), modulo);
            PolynomialTerm term(degree, coefficient);
            product.terms.push_back(term);
        }
    }
    // Combine like terms by adding coefficients of terms with the same degree
    product.sortByDegree();
    for (auto it = product.terms.begin(); it != product.terms.end(); ++it) {
        auto it2 = std::next(it);
        while (it2 != product.terms.end() && it2->getDegree() == it->getDegree()) {
            it->setCoefficient(NumberAddition::run(it->getCoefficient(), it2->getCoefficient(), modulo));
            it2 = product.terms.erase(it2);
        }
    }
    product.toField(modulo);
    return product;
}

