#ifndef LAB_RINGPOLYNOMIALADDITION_H
#define LAB_RINGPOLYNOMIALADDITION_H

#include "utils/RingPolynomial.h"

class RingPolynomialAddition {
public:
    static RingPolynomial run(RingPolynomial a, RingPolynomial b, unsigned int modulo);

private:
    static RingPolynomial add(const RingPolynomial& a, const RingPolynomial& b, unsigned int modulo);
};

#endif //LAB_RINGPOLYNOMIALADDITION_H
