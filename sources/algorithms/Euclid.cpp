#include <algorithms/PolynomialMultiplication.h>
#include <algorithms/PolynomialAddition.h>
#include <algorithms/PolynomialSubtraction.h>
#include <algorithms/PolynomialDivision.h>
#include <algorithms/PolynomialRemainder.h>
#include "utils/FieldPolynomial.h"
#include "algorithms/Euclid.h"


FieldPolynomial Euclid::run(FieldPolynomial a, FieldPolynomial b)
{
    FieldPolynomial r0 = a;
    FieldPolynomial r1 = b;
    FieldPolynomial s0 = FieldPolynomial({{0, 1}});
    FieldPolynomial s1 = FieldPolynomial();
    FieldPolynomial t0 = FieldPolynomial();
    FieldPolynomial t1 = FieldPolynomial({{0, 1}});

    while (!r1.isZero()) {
        FieldPolynomial q = PolynomialDivision::run(r0, r1,0);
        FieldPolynomial temp_r = PolynomialSubtraction::run(r0, PolynomialMultiplication::run(q, r1, 0), 0);
        FieldPolynomial temp_s = PolynomialSubtraction::run(s0, PolynomialMultiplication::run(q, s1, 0), 0);
        FieldPolynomial temp_t = PolynomialSubtraction::run(t0, PolynomialMultiplication::run(q, t1, 0), 0);

        r0 = r1;
        r1 = temp_r;
        s0 = s1;
        s1 = temp_s;
        t0 = t1;
        t1 = temp_t;
    }

    // Make sure the inverse exists
    if (r0.getDegree() == 0 && r0.getCoefficient(0) == Number(1)) {
        return t0;
    } else {
        throw std::runtime_error("The inverse does not exist.");
    }
}