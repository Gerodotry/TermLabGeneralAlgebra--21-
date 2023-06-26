#include "utils/FieldPolynomial.h"
#include "algorithms/PolynomialMultiplication.h"
#include "algorithms/PolynomialAddition.h"
#include "algorithms/PolynomialSubtraction.h"
#include "algorithms/PolynomialDivision.h"
#include "algorithms/PolynomialRemainder.h"
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
            term.coefficient = term.coefficient * Number(R);
        }

        FieldPolynomial h(g.terms);
        for (int i = h.getDegree().get() - 1; i >= 0 && h.getDegree() > modulo; --i) {
            h = PolynomialRemainder::run(h, { { i, 1 }, { 0, 1 } }, 0);
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
        if (term.coefficient.isZero()) {
            return false;
        }
    }
    return true;
}


FieldPolynomial::FieldPolynomial(int n, int value) : Polynomial(n, value) {

}

void FieldPolynomial::toField(const Number &modulo) {
    dropZeroes();

    if (getDegree() > modulo) {
        long long R = (2 << (int) log2(modulo.get())) + 1;
        long long U = calculateU(R, modulo.get());

        FieldPolynomial g = FieldPolynomial(terms);

        for (auto &term: g.terms) {
            term.coefficient = term.coefficient * Number(R);
        }

        FieldPolynomial h(g.terms);
        for (int i = h.getDegree().get() - 1; i >= 0 && h.getDegree() > modulo; --i) {
            h = PolynomialRemainder::run(h, { { i, 1 }, { 0, 1 } }, 0);
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
