#include "utils/PolynomialTerm.h"

PolynomialTerm::PolynomialTerm() {
    this->degree = Number(1);
    this->coeff = Number(1);
}

PolynomialTerm::PolynomialTerm(const Number &degree, const Number &coefficient) {
    this->degree = degree;
    this->coeff = coefficient;
}

PolynomialTerm::PolynomialTerm(const int &degree, const int &coefficient) {
    this->degree = Number(degree);
    this->coeff = Number(coefficient);
}

PolynomialTerm::PolynomialTerm(const unsigned int &degree, const unsigned int &coefficient) {
    this->degree = Number(degree);
    this->coeff = Number(coefficient);
}

PolynomialTerm::PolynomialTerm(const std::string &degree, const std::string &coefficient) {
    this->degree = Number(degree);
    this->coeff = Number(coefficient);
}

void PolynomialTerm::toField(unsigned int modulo) {
    this->degree.toField(modulo);
    this->coeff.toField(modulo);
}

bool PolynomialTerm::isZero() const {
    return coeff.isZero();
}

std::string PolynomialTerm::toString() const {
    std::string coefficient = (degree.isZero()) ? coeff.toString() : coeffToString();
    if (!coeff.isZero() && !degree.isZero()) {
        std::string term = (degree.toString() == "1") ? "x" : ("x^" + degree.toString());
        coefficient += term;
    }
    return coefficient;
}

std::string PolynomialTerm::coeffToString() const {
    std::string coefficient = coeff.toString(true);
    std::string result;
    if (!coeff.isPositive) {
        result = "-";
    }
    if (coeff.isZero() || coefficient != "1") {
        result += coefficient;
    }
    return result;
}
