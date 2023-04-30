#include "utils/PolynomialTerm.h"

PolynomialTerm::PolynomialTerm() {
    degree = Number(1);
    coefficient = Number(1);
}

PolynomialTerm::PolynomialTerm(const Number &degree, const Number &coefficient): degree(degree), coefficient(coefficient) {}

PolynomialTerm::PolynomialTerm(const int &degree, const int &coefficient): degree(degree), coefficient(coefficient) {}

PolynomialTerm::PolynomialTerm(const unsigned int &degree, const unsigned int &coefficient): degree(degree), coefficient(coefficient) {}

PolynomialTerm::PolynomialTerm(const std::string &degree, const std::string &coefficient): degree(degree), coefficient(coefficient) {}

void PolynomialTerm::toField(unsigned int modulo) {
    degree.toField(modulo);
    coefficient.toField(modulo);
}

bool PolynomialTerm::isZero() const {
    return coefficient.isZero();
}

std::string PolynomialTerm::toString() const {
    std::string coeff = (degree.isZero()) ? coefficient.toString() : coeffToString();
    if (!coefficient.isZero() && !degree.isZero()) {
        std::string term = (degree.toString() == "1") ? "x" : ("x^" + degree.toString());
        coeff += term;
    }
    return coeff;
}

std::string PolynomialTerm::coeffToString() const {
    std::string coeff = coefficient.toString(true);
    std::string result;
    if (!coefficient.isPositive) {
        result = "-";
    }
    if (coefficient.isZero() || coeff != "1") {
        result += coeff;
    }
    return result;
}

Number PolynomialTerm::getDegree() const {
    return degree;
}

Number PolynomialTerm::getCoefficient() const {
    return coefficient;
}

void PolynomialTerm::setDegree(const Number& newDegree) {
    degree = newDegree;
}

void PolynomialTerm::setCoefficient(const Number& newCoefficient) {
    coefficient = newCoefficient;
}
