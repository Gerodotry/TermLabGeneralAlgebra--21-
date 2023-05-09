#include <algorithms/PolynomialMultiplication.h>
#include <algorithms/PolynomialSubtraction.h>
#include "utils/FieldPolynomial.h"
#include "algorithms/Euclid.h"

FieldPolynomial Euclid::run(FieldPolynomial r1, FieldPolynomial r2, FieldPolynomial &a, FieldPolynomial &b, unsigned int modulo) {
    if (modulo) {
        r1.toField(modulo);
        r2.toField(modulo);
    }

    return euclid_inversion(r1, r2, a, b, modulo);
}

FieldPolynomial Euclid::euclid_inversion(FieldPolynomial &r1, FieldPolynomial &r2, FieldPolynomial &a, FieldPolynomial &b, unsigned int modulo) {

    std::vector<FieldPolynomial> e;
    FieldPolynomial gcd;

    euclid(r1, r2, gcd, a, b, modulo);

    e.push_back(gcd);
    e.push_back(a);
    e.push_back(b);

    return gcd;
}

void Euclid::inversion(FieldPolynomial r1, FieldPolynomial r2, FieldPolynomial x1, FieldPolynomial x2, FieldPolynomial y1, FieldPolynomial y2,
                       FieldPolynomial &gcd, FieldPolynomial &a, FieldPolynomial &b, unsigned int modulo) {
    FieldPolynomial zeroPoly({{0, 0}});

    while (!r2.isZero()) {
        FieldPolynomial quotient = FieldPolynomial::PolyDiv(r1, r2);

        FieldPolynomial r3 = PolynomialSubtraction::run(r1, PolynomialMultiplication::run(r2, quotient, modulo), modulo);
        FieldPolynomial x3 = PolynomialSubtraction::run(x1, PolynomialMultiplication::run(x2, quotient, modulo), modulo);
        FieldPolynomial y3 = PolynomialSubtraction::run(y1, PolynomialMultiplication::run(y2, quotient, modulo), modulo);

        r1 = r2;
        r2 = r3;
        x1 = x2;
        x2 = x3;
        y1 = y2;
        y2 = y3;
    }

    gcd = r1;
    a = x1;
    b = y1;
}

void Euclid::euclid(FieldPolynomial r1, FieldPolynomial r2, FieldPolynomial &gcd, FieldPolynomial &a, FieldPolynomial &b,
               unsigned int modulo) {

    Number d1 = r1.getDegree();
    Number d2 = r2.getDegree();

    inversion(d1 > d2 ? r1 : r2, d1 < d2 ? r1 : r2, FieldPolynomial(1), FieldPolynomial(0), FieldPolynomial(0),
              FieldPolynomial(1), gcd, d1 > d2 ? a : b, d1 < d2 ? a : b, modulo);
}

