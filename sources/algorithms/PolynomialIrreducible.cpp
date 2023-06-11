//
// Created by sofia on 11.06.2023.
//

#include <random>
#include "algorithms/PolynomialIrreducible.h"
#include "algorithms/Gcd.h"

int PolynomialIrreducible::polynomialDegree(const vector<int> &polynomial) {
    return polynomial.size() - 1;
}

std::vector<int> PolynomialIrreducible::convolution(const vector<int> &a, const vector<int> &b) {
    return std::vector<int>();
}

std::vector<int> PolynomialIrreducible::polynomialMod(const vector<int> &dividend, const vector<int> &divisor) {
    std::vector<int> quotient;
    std::vector<int> remainder(dividend);
    while (polynomialDegree(remainder) >= polynomialDegree(divisor)) {
        int factor = remainder.back() / divisor.back();
        int degreeDiff = polynomialDegree(remainder) - polynomialDegree(divisor);
        quotient.push_back(factor);
        for (int i = 0; i <= degreeDiff; ++i) {
            int j = i + polynomialDegree(dividend) - polynomialDegree(divisor);
            remainder[j] -= factor * divisor[i];
        }
        while (remainder.back() == 0 && !remainder.empty()) {
            remainder.pop_back();
        }
    }
    return remainder;
}

bool PolynomialIrreducible::isIrreducible(const vector<int> &polynomial, int fieldSize) {
    std::uniform_int_distribution<int> dis(1, fieldSize - 1);
    std::vector<int> x = {1, 1};
    for (int i = 1; i <= fieldSize / 2; ++i) {
        std::vector<int> power = {1};
        for (int j = 0; j < i; ++j) {
            power = polynomialMod(convolution(power, x), polynomial);
        }
        std::vector<int> gcdResult = Gcd::gcd(polynomial, power, 2);
        if (gcdResult != std::vector<int>({1})) {
            return false;
        }
    }
    return true;
}