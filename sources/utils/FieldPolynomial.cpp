#include "utils/FieldPolynomial.h"
#include <utility>
#include <initializer_list>

void FieldPolynomial::toField(unsigned int modulo) {
    dropZeroes();
    for (auto term : terms) {
        term.toField(modulo);
    }
}

FieldPolynomial::FieldPolynomial(const std::initializer_list<PolynomialTerm> &terms) : Polynomial(terms) {

}

FieldPolynomial::FieldPolynomial(const std::vector<PolynomialTerm> &terms) : Polynomial(terms) {

}

FieldPolynomial::FieldPolynomial(const std::vector<std::string> &degrees, const std::vector<std::string> &coefficients) : Polynomial(degrees, coefficients) {

}

FieldPolynomial::FieldPolynomial(const std::vector<Number> &degrees, const std::vector<Number> &coefficients) : Polynomial(degrees, coefficients) {

}

