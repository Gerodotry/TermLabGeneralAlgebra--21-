#ifndef LAB_POLYNOMIALMULTIPLICATION_H
#define LAB_POLYNOMIALMULTIPLICATION_H

#include "utils/Polynomial.h"

class PolynomialMultiplication {
public:
    static Polynomial run(Polynomial a, Polynomial b, unsigned int modulo);

    static Polynomial multiply(const Polynomial& a, const Polynomial& b, unsigned int modulo);
};


#endif //LAB_POLYNOMIALMULTIPLICATION_H
