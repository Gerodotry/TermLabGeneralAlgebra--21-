//
// Created by Dklishch on 5/8/2023.
//

#include "utils/RawPolynomial.h"

RawPolynomial::RawPolynomial(const std::vector<int> &degrees, const std::vector<int> &coefs) {
    add(degrees, coefs);
}

RawPolynomial::RawPolynomial() {

}

RawPolynomial::RawPolynomial(const std::vector<std::string> &degrees, const std::vector<std::string> &coefs) {
    std::vector<int> parsedDegrees;
    std::vector<int> parsedCoefs;

    parsedDegrees.reserve(degrees.size());
    for (const auto& degree: degrees) {
        parsedDegrees.push_back(std::stoi(degree));
    }

    parsedCoefs.reserve(coefs.size());
    for (const auto& coef: coefs) {
        parsedCoefs.push_back(std::stoi(coef));
    }

    add(parsedDegrees, parsedCoefs);
}

void RawPolynomial::add(const std::vector<int>& degrees, const std::vector<int>& coefs) {

    int max = 0;
    for (int degree : degrees) {
        max = std::max(max, degree);
        _degrees.push_back(degree);
    }

    coefficients.reserve(max + 1);
    for (int i = 0; i <= max; ++i) {
        coefficients.push_back(0);
    }

    for (int i = 0; i < degrees.size(); ++i) {
        coefficients[degrees[i]] = coefs[i];
    }
}

std::string RawPolynomial::toString() {
    std::string result;
    for (int i = 0; i < coefficients.size(); ++i) {
        if (coefficients[i]) {
            std::string termString = std::to_string(coefficients[i]);
            result += (termString[0] == '-') ? termString : ("+" + termString);
            int degree = coefficients.size() - i - 1;
            if (degree > 1) {
                result += "x^" + std::to_string(degree);
            } else if (degree == 1) {
                result += "x";
            }
        }
    }
    return result.size() ? result.substr(1) : "0";
}

RawPolynomial::RawPolynomial(const std::vector<int> &coefficients): coefficients(coefficients) {

}

RawPolynomial &RawPolynomial::operator=(const RawPolynomial &polynomial) {
    coefficients = polynomial.coefficients;
    _degrees = polynomial._degrees;
    return *this;
}
