#include "utils/Polynomial.h"

#include <utility>
#include <initializer_list>

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
    sortByDegree();
    for (auto& term : terms) {
        std::string termString = term.toString();
        result += (termString[0] == '-') ? termString : ("+" + termString);
    }
    return result.substr(1);
}

Polynomial::Polynomial(const std::initializer_list<PolynomialTerm>& terms): terms(terms){}

Polynomial::Polynomial(std::vector<Number> degrees, std::vector<Number> coefficients) {
    if (degrees.size() == coefficients.size()) {
        for (int i = 0; i < degrees.size(); i++) {
            terms.push_back(PolynomialTerm(degrees[i], coefficients[i]));
        }
    }
}

template<typename T>
Polynomial::Polynomial(std::vector<T> degrees, std::vector<T> coefficients) {
    if (degrees.size() == coefficients.size()) {
        for (int i = 0; i < degrees.size(); i++) {
            terms.push_back(PolynomialTerm(degrees[i], coefficients[i]));
        }
    }
}

void Polynomial::sortByDegree(bool ascending) {
    std::sort(terms.begin(), terms.end(), [&ascending](const PolynomialTerm& leftTerm, const PolynomialTerm& rightTerm) {
        if (ascending) {
            return leftTerm.getDegree() > rightTerm.getDegree();
        }
        return leftTerm.getDegree() < rightTerm.getDegree();
    });
}

void Polynomial::sortByCoefficient(bool ascending) {
    std::sort(terms.begin(), terms.end(), [&ascending](const PolynomialTerm& leftTerm, const PolynomialTerm& rightTerm) {
        if (ascending) {
            return leftTerm.getCoefficient() > rightTerm.getCoefficient();
        }
        return leftTerm.getCoefficient() < rightTerm.getCoefficient();
    });
}

Polynomial::Polynomial(const std::vector<std::string> &degrees, const std::vector<std::string> &coefficients) {
    if (degrees.size() == coefficients.size()) {
        for (int i = 0; i < degrees.size(); i++) {
            terms.push_back(PolynomialTerm(Number(degrees[i]), Number(coefficients[i])));
        }
    }
}

Polynomial& Polynomial::operator = (const Polynomial &polynomial) {
    terms = polynomial.terms;
    return *this;
}