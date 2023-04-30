#include "utils/Polynomial.h"

#include <utility>

void Polynomial::dropZeroes() {
    for (auto it = this->terms.begin(); it != this->terms.end(); ) {
        if (it->isZero()) {
            it = this->terms.erase(it);
        } else {
            ++it;
        }
    }
}

void Polynomial::toField(unsigned int modulo) {
    dropZeroes();
    for (auto term : terms) {
        term.toField(modulo);
    }
}

std::string Polynomial::toString() {
    if (this->terms.empty()) {
        return "0";
    }
    std::string result;
    sortByDegree();
    for (const auto& term : this->terms) {
        std::string termString = term.toString();
        result += (termString[0] == '-') ? termString : ("+" + termString);
    }
    return result.substr(1);
}

Polynomial::Polynomial(const std::vector<PolynomialTerm>& terms) {
    this->terms = terms;
}

Polynomial::Polynomial(std::vector<Number> degrees, std::vector<Number> coefficients) {
    if (degrees.size() == coefficients.size()) {
        for (int i = 0; i < degrees.size(); i++) {
            this->terms[i] = PolynomialTerm(degrees[i], coefficients[i]);
        }
    }
}

Polynomial::Polynomial(std::vector<int> degrees, std::vector<int> coefficients) {
    if (degrees.size() == coefficients.size()) {
        for (int i = 0; i < degrees.size(); i++) {
            this->terms[i] = PolynomialTerm(degrees[i], coefficients[i]);
        }
    }
}

Polynomial::Polynomial(std::vector<unsigned int> degrees, std::vector<unsigned int> coefficients) {
    if (degrees.size() == coefficients.size()) {
        for (int i = 0; i < degrees.size(); i++) {
            this->terms[i] = PolynomialTerm(degrees[i], coefficients[i]);
        }
    }
}

Polynomial::Polynomial(std::vector<std::string> degrees, std::vector<std::string> coefficients) {
    if (degrees.size() == coefficients.size()) {
        for (int i = 0; i < degrees.size(); i++) {
            this->terms[i] = PolynomialTerm(degrees[i], coefficients[i]);
        }
    }
}

void Polynomial::sortByDegree(bool ascending) {
    std::sort(this->terms.begin(), this->terms.end(), [&ascending](const PolynomialTerm& leftTerm, const PolynomialTerm& rightTerm) {
        if (ascending) {
            return leftTerm.getDegree() > rightTerm.getDegree();
        }
        return leftTerm.getDegree() < rightTerm.getDegree();
    });
}

void Polynomial::sortByCoefficient(bool ascending) {
    std::sort(this->terms.begin(), this->terms.end(), [&ascending](const PolynomialTerm& leftTerm, const PolynomialTerm& rightTerm) {
        if (ascending) {
            return leftTerm.getCoefficient() > rightTerm.getCoefficient();
        }
        return leftTerm.getCoefficient() < rightTerm.getCoefficient();
    });
}