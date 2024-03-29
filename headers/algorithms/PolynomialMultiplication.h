#ifndef LAB_POLYNOMIALMULTIPLICATION_H
#define LAB_POLYNOMIALMULTIPLICATION_H

#include "utils/RingPolynomial.h"
#include "NumberAddition.h"
#include "NumberMultiplication.h"

class PolynomialMultiplication {
public:
    template<class T>
    static T run(T a, T b, Number modulo);
private:
    template<class T>
    static T multiply(const T& a, const T& b, Number& modulo);
};

template<class T>
T PolynomialMultiplication::run(T a, T b, Number modulo) {
    if (!modulo.isZero()) {
        a.toField(modulo);
        b.toField(modulo);
    }
    return multiply(a, b, modulo);
}
template<class T>
T PolynomialMultiplication::multiply(const T& a, const T& b, Number& modulo) {
    T product;
    // Multiply each term of a with each term of b and add the results to the product polynomial
    for (const auto& termA : a.terms) {
        for (const auto& termB : b.terms) {
            Number degree = termA.getDegree() + termB.getDegree();
            Number coefficient = termA.getCoefficient() * termB.getCoefficient();
            PolynomialTerm term({degree, coefficient});
            product.terms.push_back(term);
        }
    }
    // Combine like terms by adding coefficients of terms with the same degree
    product.sortByDegree();
    for (auto it = product.terms.begin(); it != product.terms.end(); ++it) {
        auto it2 = std::next(it);
        while (it2 != product.terms.end() && it2->getDegree() == it->getDegree()) {
            it->setCoefficient(it->getCoefficient() + it2->getCoefficient());
            it2 = product.terms.erase(it2);
        }
    }
    if (!modulo.isZero()) {
        product.toField(modulo);
    }
    return product;
}

#endif //LAB_POLYNOMIALMULTIPLICATION_H
