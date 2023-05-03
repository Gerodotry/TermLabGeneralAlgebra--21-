#include "utils/RingPolynomial.h"

#include <utility>
#include <initializer_list>

void RingPolynomial::dropZeroes() {
    for (auto it = terms.begin(); it != terms.end(); ) {
        if (it->isZero()) {
            it = terms.erase(it);
        } else {
            ++it;
        }
    }
}

void RingPolynomial::toField(unsigned int modulo) {
    dropZeroes();
    for (auto term : terms) {
        term.toField(modulo);
    }
}

std::string RingPolynomial::toString() {
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

RingPolynomial::RingPolynomial(const std::initializer_list<PolynomialTerm>& terms): terms(terms){}

RingPolynomial::RingPolynomial(std::vector<Number> degrees, std::vector<Number> coefficients) {
    if (degrees.size() == coefficients.size()) {
        for (int i = 0; i < degrees.size(); i++) {
            terms.push_back(PolynomialTerm(degrees[i], coefficients[i]));
        }
    }
}

template<typename T>
RingPolynomial::RingPolynomial(std::vector<T> degrees, std::vector<T> coefficients) {
    if (degrees.size() == coefficients.size()) {
        for (int i = 0; i < degrees.size(); i++) {
            terms.push_back(PolynomialTerm(degrees[i], coefficients[i]));
        }
    }
}

void RingPolynomial::sortByDegree(bool ascending) {
    std::sort(terms.begin(), terms.end(), [&ascending](const PolynomialTerm& leftTerm, const PolynomialTerm& rightTerm) {
        if (ascending) {
            return leftTerm.getDegree() > rightTerm.getDegree();
        }
        return leftTerm.getDegree() < rightTerm.getDegree();
    });
}

void RingPolynomial::sortByCoefficient(bool ascending) {
    std::sort(terms.begin(), terms.end(), [&ascending](const PolynomialTerm& leftTerm, const PolynomialTerm& rightTerm) {
        if (ascending) {
            return leftTerm.getCoefficient() > rightTerm.getCoefficient();
        }
        return leftTerm.getCoefficient() < rightTerm.getCoefficient();
    });
}

RingPolynomial::RingPolynomial(const std::vector<std::string> &degrees, const std::vector<std::string> &coefficients) {
    if (degrees.size() == coefficients.size()) {
        for (int i = 0; i < degrees.size(); i++) {
            terms.push_back(PolynomialTerm(Number(degrees[i]), Number(coefficients[i])));
        }
    }
}

RingPolynomial& RingPolynomial::operator = (const RingPolynomial &polynomial) {
    terms = polynomial.terms;
    return *this;
}