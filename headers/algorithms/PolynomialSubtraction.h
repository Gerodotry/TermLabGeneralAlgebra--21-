#ifndef LAB_POLYNOMIALSUBTRACTION_H
#define LAB_POLYNOMIALSUBTRACTION_H

#include "utils/Polynomial.h"

class PolynomialSubtraction {
public:
    static Polynomial run(Polynomial a, Polynomial b, unsigned int modulo);

    static Polynomial subtract(const Polynomial& a, const Polynomial& b, unsigned int modulo);
};

#endif //LAB_POLYNOMIALSUBTRACTION_H
