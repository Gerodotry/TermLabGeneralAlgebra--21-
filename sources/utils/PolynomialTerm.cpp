#include "utils/PolynomialTerm.h"

#include <utility>

PolynomialTerm::PolynomialTerm() {
    degree = Number(1);
    coefficient = Number(1);
}

PolynomialTerm::PolynomialTerm(Number degree, Number coefficient):
    degree(std::move(degree)),
    coefficient(std::move(coefficient)) {}

PolynomialTerm::PolynomialTerm(int degree, int coefficient):
    degree(degree),
    coefficient(coefficient) {}

PolynomialTerm::PolynomialTerm(unsigned int degree,  unsigned int coefficient):
    degree(degree),
    coefficient(coefficient) {}

PolynomialTerm::PolynomialTerm(const std::string& degree, const std::string& coefficient):
    degree(degree),
    coefficient(coefficient) {}

void PolynomialTerm::toField(unsigned int modulo) {
    coefficient.toField(modulo);
}

bool PolynomialTerm::isZero() {
    return coefficient.isZero();
}

std::string PolynomialTerm::toString() {
    std::string coeff = (degree.isZero()) ? coefficient.toString() : coeffToString();
    if (!coefficient.isZero() && !degree.isZero()) {
        std::string term = (degree.toString() == "1") ? "x" : ("x^" + degree.toString());
        coeff += term;
    }
    return coeff;
}

std::string PolynomialTerm::coeffToString() {
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

bool PolynomialTerm::operator==(const PolynomialTerm &term) const {
    return degree == term.degree && coefficient == term.coefficient;
}
