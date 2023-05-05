#ifndef LAB_RINGPOLYNOMIALMULTIPLICATION_H
#define LAB_RINGPOLYNOMIALMULTIPLICATION_H

#include "utils/RingPolynomial.h"

class RingPolynomialMultiplication {
public:
    static RingPolynomial run(RingPolynomial a, RingPolynomial b, unsigned int modulo);

private:
    static RingPolynomial multiply(const RingPolynomial& a, const RingPolynomial& b, unsigned int modulo);
};


#endif //LAB_RINGPOLYNOMIALMULTIPLICATION_H
