//
// Created by sofia on 11.06.2023.
//

#include "algorithms/PolynomialIrreducible.h"
#include "algorithms/Gcd.h"

vector<int> PolynomialIrreducible::multiply(const vector<int> &a, const vector<int> &b) {
    vector<int> result(a.size() + b.size() - 1, 0);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            result[i + j] ^= (a[i] & b[j]);
        }
    }
    return result;
}

vector<int> PolynomialIrreducible::reduce(const vector<int> &a, const vector<int> &b) {
    vector<int> result(a);
    while (result.size() >= b.size()) {
        const vector<int> quotient = { result[0] / b[0] };
        vector<int> temp(b.size(), 0);
        for (int i = 0; i < b.size(); ++i) {
            temp[i] = quotient[0] * b[i];
        }
        for (int i = 0; i < result.size() && i < temp.size(); ++i) {
            result[i] ^= temp[i];
        }
        while (!result.empty() && result[0] == 0) {
            result.erase(result.begin());
        }
    }
    return result;
}

vector<int> PolynomialIrreducible::power_mod(const vector<int> &a, const vector<int> &exp, const vector<int> &modulus) {
    vector<int> result = { 1 };
    vector<int> base = a;
    vector<int> exponent = exp;
    while (!exponent.empty()) {
        if (exponent[0] & 1) {
            result = reduce(multiply(result, base), modulus);
        }
        base = reduce(multiply(base, base), modulus);
        for (int & i : exponent) {
            i /= 2;
        }
    }
    return result;
}

bool PolynomialIrreducible::test_irreducibility(const vector<int> &polynomial) {
    if (polynomial.empty() || (polynomial[0] == 0 && polynomial.size() > 1)) {
        return false;
    }
    const int n = polynomial.size() - 1;
    if (n <= 1) {
        return true;
    }
    vector<int> alpha = { 0, 1 };
    vector<int> P = polynomial;
    for (int i = 1; i <= n / 2; ++i) {
        vector<int> tmp = reduce(power_mod(alpha, { i }, P), polynomial);
        for (int j = 0; j < alpha.size(); ++j) {
            tmp[j] ^= alpha[j];
        }
        if (tmp.empty() || Gcd::gcd(polynomial, tmp, 2).size() > 0) {
            return false;
        }
    }
    return true;
}
