#include "utils/FieldPolynomial.h"
#include "algorithms/PolynomialMultiplication.h"
#include "algorithms/PolynomialAddition.h"
#include "algorithms/PolynomialSubtraction.h"
#include <initializer_list>
#include <cmath>
#include <stdexcept>

void FieldPolynomial::toField(int modulo) {
    dropZeroes();

    if (getDegree() > modulo) {
        long long R = (2 << (int) log2(modulo)) + 1;
        long long U = calculateU(R, modulo);

        FieldPolynomial g = FieldPolynomial(terms);

        for (auto &term: g.terms) {
            term.coefficient = NumberMultiplication::run(term.coefficient, Number(R), 0);
        }

        FieldPolynomial h(g.terms);
        for (int i = h.getDegree().get() - 1; i >= 0 && h.getDegree() > modulo; --i) {
            h = PolyDiv(h, { { i, 1 }, { 0, 1 } });
        }

        for (auto& term: h.terms) {
            term.coefficient = NumberMultiplication::run(term.coefficient, Number(U), modulo);
        }

        terms = h.terms;
    }

    for (auto& term : terms) {
        term.toField(modulo);
    }
    dropZeroes();
}

FieldPolynomial::FieldPolynomial(const std::initializer_list<PolynomialTerm> &terms) : Polynomial(terms) {

}

FieldPolynomial::FieldPolynomial(const std::vector<PolynomialTerm> &terms) : Polynomial(terms) {

}

FieldPolynomial::FieldPolynomial(const std::vector<std::string> &degrees, const std::vector<std::string> &coefficients)
        : Polynomial(degrees, coefficients) {

}

FieldPolynomial::FieldPolynomial(const std::vector<Number> &degrees, const std::vector<Number> &coefficients)
        : Polynomial(degrees, coefficients) {

}

int FieldPolynomial::calculateBitsNumber(int number) {
    int temp = number, result = 0;
    while (temp) {
        result += temp % 2;
        temp /= 2;
    }
    return result;
}

long long FieldPolynomial::calculateValue(long long int t, long long int module) {
    long long result = 0;
    for (auto term: terms) {

        long long tmp = 1;
        for (int i = 0; term.degree > i; ++i) {
            tmp = (tmp * t) % module;
        }

        term.coefficient.toField(module);
        tmp = (tmp * term.coefficient.get()) % module;

        result = (result + tmp) % module;
    }

    return result;
}

FieldPolynomial FieldPolynomial::PolyDiv(const FieldPolynomial& dividend, FieldPolynomial divisor) {
    if (divisor.isZero()) {
        throw std::invalid_argument("Division by zero");
    }

    FieldPolynomial quotient;
    FieldPolynomial remainder(dividend);

    remainder.sortByDegree();
    divisor.sortByDegree();

    while (remainder.getDegree() >= divisor.getDegree()) {
        while (!remainder.terms.empty() && remainder.terms.front().coefficient.isZero()) {
            remainder.terms.erase(remainder.terms.begin());
        }

        Number degree_diff = NumberSubtraction::run(remainder.terms.front().degree, divisor.terms.front().degree, 0);
        Number coeff_ratio = NumberDivision::run(remainder.terms.front().coefficient, divisor.terms.front().coefficient, 0);

        for (auto& term : divisor.terms) {
            term.coefficient = NumberMultiplication::run(term.coefficient, coeff_ratio, 0);
            term.degree = NumberAddition::run(term.degree, degree_diff, 0);
        }

        remainder = PolynomialSubtraction::run(remainder, divisor, 0);

        for (auto& term : divisor.terms) {
            term.coefficient = NumberDivision::run(term.coefficient, coeff_ratio, 0);
            term.degree = NumberSubtraction::run(term.degree, degree_diff, 0);
        }
    }

    return remainder.terms.empty() ? FieldPolynomial({ {0, 0} }) : remainder;
}



long long FieldPolynomial::calculateU(long long R, long long module) {
    long long u = 1;
    long long t = R;
    long long m = module;

    while (t != 0) {
        long long q = m / t;
        long long r = m % t;
        m = t;
        t = r;

        long long u_next = u - q * R;
        u = u_next;
    }

    u %= module;
    if (u < 0) {
        u += module;
    }

    return u;
}

bool FieldPolynomial::isZero() {
    for (auto& term : terms) {
        if (!term.coefficient.isZero()) {
            return false;
        }
    }
    return true;
}


FieldPolynomial::FieldPolynomial(int n) : Polynomial(n) {

}
