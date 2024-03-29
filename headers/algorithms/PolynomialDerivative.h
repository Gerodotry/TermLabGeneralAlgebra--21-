#ifndef LAB_POLYNOMIALDERIVATIVE_H
#define LAB_POLYNOMIALDERIVATIVE_H

#include "utils/RingPolynomial.h"
#include "NumberMultiplication.h"
#include "NumberSubtraction.h"

class PolynomialDerivative {
public:
	static RingPolynomial run(RingPolynomial p, Number modulo);
private:
	static RingPolynomial getDerivative(RingPolynomial& p, Number& modulo);
};

#endif //LAB_POLYNOMIALDERIVATIVE_H