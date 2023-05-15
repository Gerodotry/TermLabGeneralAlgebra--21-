#include "utils/Polynomial.h"

#include <utility>
#include <initializer_list>

Polynomial::Polynomial(const std::initializer_list<PolynomialTerm>& terms): terms(terms){}

Polynomial::Polynomial(const std::vector<PolynomialTerm>& terms): terms(terms){}

Polynomial::Polynomial(const std::vector<std::string> &degrees, const std::vector<std::string> &coefficients) {
    if (degrees.size() == coefficients.size()) {
        for (int i = 0; i < degrees.size(); i++) {
            terms.push_back(PolynomialTerm(Number(degrees[i]), Number(coefficients[i])));
        }
    }
}

Polynomial::Polynomial(std::vector<Number> degrees, std::vector<Number> coefficients) {
    if (degrees.size() == coefficients.size()) {
        for (int i = 0; i < degrees.size(); i++) {
            terms.push_back(PolynomialTerm(degrees[i], coefficients[i]));
        }
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

Polynomial& Polynomial::operator=(const Polynomial &polynomial) {
    terms = polynomial.terms;
    return *this;
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

void Polynomial::dropZeroes() {
    for (auto it = terms.begin(); it != terms.end(); ) {
        if (it->isZero()) {
            it = terms.erase(it);
        } else {
            ++it;
        }
    }
}

Number Polynomial::getDegree() {
    Number degree(0);
    for (auto& term: terms) {
        if (degree < term.degree && !term.coefficient.isZero()) {
            degree = term.degree;
        }
    }
    return degree;
}

Number Polynomial::getCoefficient(int degree) {
    for (auto &term: terms) {
        if (term.degree == degree) {
            return term.coefficient;
        }
    }
    return Number(0);
}

void Polynomial::toField(int modulo) {

}

Polynomial::Polynomial(int n, int value) {
    for (int i = 0; i < n; ++i) {
        terms.push_back({i, value});
    }
}

bool Polynomial::operator==(const Polynomial &polynomial) const {
    return polynomial.terms == terms;
}