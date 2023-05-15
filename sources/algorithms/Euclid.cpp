#include <algorithms/PolynomialMultiplication.h>
#include <algorithms/PolynomialAddition.h>
#include <algorithms/PolynomialSubtraction.h>
#include <algorithms/PolynomialDivision.h>
#include "utils/FieldPolynomial.h"
#include "algorithms/Euclid.h"


FieldPolynomial Euclid::run(FieldPolynomial r1, FieldPolynomial r2)
{
    FieldPolynomial a, gcd, b, result,mod;

    mod = r2;

    Number d1 = r1.getDegree();
    Number d2 = r2.getDegree();

    inversion(d1 > d2 ? r1 : r2, d1 < d2 ? r1 : r2, FieldPolynomial(1, 1), FieldPolynomial(1), FieldPolynomial(1), FieldPolynomial(1, 1), gcd, d1 > d2 ? a : b, d1 < d2 ? a : b);

    return PolynomialAddition::run(a,mod,0);
}

void Euclid::inversion(FieldPolynomial r1, FieldPolynomial r2, FieldPolynomial x1, FieldPolynomial x2, FieldPolynomial y1, FieldPolynomial y2,
                       FieldPolynomial& gcd, FieldPolynomial& a, FieldPolynomial& b) {

    FieldPolynomial q = PolynomialDivision::run(r1, r2, 0);

    FieldPolynomial r3 = PolynomialSubtraction::run(r1, PolynomialMultiplication::run(r2, q, 0), 0);
    FieldPolynomial x3 = PolynomialSubtraction::run(x1, PolynomialMultiplication::run(x2, q, 0), 0);
    FieldPolynomial y3 = PolynomialSubtraction::run(y1, PolynomialMultiplication::run(y2, q, 0), 0);

    if (!r3.isZero()) {
        inversion(r2, r3, x2, x3, y2, y3, gcd, a, b);
    }
    else {
        gcd = r2;
        a = x2;
        b = y2;
    }
}