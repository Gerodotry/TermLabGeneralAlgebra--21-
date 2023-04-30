#include "utils/PolynomialTerm.h"
#include <initializer_list>

PolynomialTerm::PolynomialTerm() {
    degree = Number(1);
    coefficient = Number(1);
}

PolynomialTerm::PolynomialTerm(const std::initializer_list<Number>& degreeAndCoefficient) {
    if (degreeAndCoefficient.size() == 2) {
        auto it = degreeAndCoefficient.begin();
        degree = *it++;
        coefficient = *it;
    } else {
        throw std::invalid_argument("degreeAndCoefficient must have length 2:"
                                    "first values is degree and the second one is coefficient");
    }
}

PolynomialTerm::PolynomialTerm(const std::initializer_list<int>& degreeAndCoefficient) {
    if (degreeAndCoefficient.size() == 2) {
        auto it = degreeAndCoefficient.begin();
        degree = Number(*it++);
        coefficient = Number(*it);
    } else {
        throw std::invalid_argument("degreeAndCoefficient must have length 2:"
                                    "first values is degree and the second one is coefficient");
    }
}

PolynomialTerm::PolynomialTerm(const std::initializer_list<unsigned int>& degreeAndCoefficient) {
    if (degreeAndCoefficient.size() == 2) {
        auto it = degreeAndCoefficient.begin();
        degree = Number(*it++);
        coefficient = Number(*it);
    } else {
        throw std::invalid_argument("degreeAndCoefficient must have length 2:"
                                    "first values is degree and the second one is coefficient");
    }
}

PolynomialTerm::PolynomialTerm(const std::initializer_list<std::string>& degreeAndCoefficient) {
    if (degreeAndCoefficient.size() == 2) {
        auto it = degreeAndCoefficient.begin();
        degree = Number(*it++);
        coefficient = Number(*it);
    } else {
        throw std::invalid_argument("degreeAndCoefficient must have length 2:"
                                    "first values is degree and the second one is coefficient");
    }
}

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
