#ifndef LAB_POLYNOMIALVALUE_H
#define LAB_POLYNOMIALVALUE_H

#include "utils/RingPolynomial.h"
#include "NumberMultiplication.h"
#include "NumberAddition.h"

class PolynomialValue{
public:
	static Number run(RingPolynomial polynomial, Number point, unsigned int modulo);
private:
	static Number getValue(RingPolynomial& polynomial, Number& point, unsigned int modulo);
};

#endif //LAB_POLYNOMIALVALUE_H