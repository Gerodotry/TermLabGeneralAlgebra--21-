#include "utils/Polynomial.h"

#include <utility>

void Polynomial::dropZeroes() {
    for (auto it = terms.begin(); it != terms.end(); ) {
        if (it->isZero()) {
            it = terms.erase(it);
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
    if (terms.empty()) {
        return "0";
    }
    std::string result;
    for (const auto& term : terms) {
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
