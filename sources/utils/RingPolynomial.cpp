#include "utils/RingPolynomial.h"

#include <utility>
#include <initializer_list>

void RingPolynomial::toField(int modulo) {
    for (auto& term : terms) {
        term.toField(modulo);
    }
    dropZeroes();
}

void RingPolynomial::toField(const Number& modulo) {
    for (auto& term : terms) {
        term.toField(modulo);
    }
    dropZeroes();
}

RingPolynomial::RingPolynomial(const std::initializer_list<PolynomialTerm> &terms) : Polynomial(terms) {

}

RingPolynomial::RingPolynomial(const std::vector<PolynomialTerm> &terms) : Polynomial(terms) {

}

RingPolynomial::RingPolynomial(const std::vector<std::string> &degrees, const std::vector<std::string> &coefficients) : Polynomial(degrees, coefficients) {

}

RingPolynomial::RingPolynomial(const std::vector<Number> &degrees, const std::vector<Number> &coefficients) : Polynomial(degrees, coefficients) {

}

