#ifndef LAB_RINGPOLYNOMIALSUBTRACTION_H
#define LAB_RINGPOLYNOMIALSUBTRACTION_H

#include "utils/RingPolynomial.h"

class RingPolynomialSubtraction {
public:
    static RingPolynomial run(RingPolynomial a, RingPolynomial b, unsigned int modulo);

private:
    static RingPolynomial subtract(const RingPolynomial& a, const RingPolynomial& b, unsigned int modulo);
};

#endif //LAB_RINGPOLYNOMIALSUBTRACTION_H
