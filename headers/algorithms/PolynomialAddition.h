#ifndef LAB_POLYNOMIALADDITION_H
#define LAB_POLYNOMIALADDITION_H

#include "utils/Polynomial.h"

class PolynomialAddition {
public:
    static Polynomial run(Polynomial a, Polynomial b, unsigned int modulo);

    static Polynomial add(const Polynomial& a, const Polynomial& b, unsigned int modulo);
};

#endif //LAB_POLYNOMIALADDITION_H
