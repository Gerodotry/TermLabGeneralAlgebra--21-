#include "utils/PolynomialTerm.h"

PolynomialTerm::PolynomialTerm() {
    this->degree = Number(1);
    this->coeff = Number(1);
}

PolynomialTerm::PolynomialTerm(const Number &degree, const Number &coefficient) {
    this->degree = degree;
    this->coeff = coefficient;
}

PolynomialTerm::PolynomialTerm(int degree, int coefficient) {
    this->degree = Number(degree);
    this->coeff = Number(coefficient);
}

PolynomialTerm::PolynomialTerm(unsigned int degree, unsigned int coefficient) {
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
    return this->coeff.isZero();
}

std::string PolynomialTerm::toString() const {
    std::string coefficient = (this->degree.isZero()) ? this->coeff.toString() : coeffToString();
    if (!this->coeff.isZero() && !this->degree.isZero()) {
        std::string term = (this->degree.toString() == "1") ? "x" : ("x^" + this->degree.toString());
        coefficient += term;
    }
    return coefficient;
}

std::string PolynomialTerm::coeffToString() const {
    std::string coefficient = this->coeff.toString(true);
    std::string result;
    if (!this->coeff.isPositive) {
        result = "-";
    }
    if (this->coeff.isZero() || coefficient != "1") {
        result += coefficient;
    }
    return result;
}

Number PolynomialTerm::getDegree() const {
    return this->degree;
}

Number PolynomialTerm::getCoefficient() const {
    return this->coeff;
}

void PolynomialTerm::setDegree(const Number& newDegree) {
    this->degree = newDegree;
}

void PolynomialTerm::setCoefficient(const Number& newCoefficient) {
    this->coeff = newCoefficient;
}
