#include "algorithms/PolynomialValue.h"

Number PolynomialValue::run(RingPolynomial polynomial, Number point, unsigned int modulo) {
	if (modulo) {
		polynomial.toField(modulo);
	}

	return getValue(polynomial, point, modulo);
}

Number PolynomialValue::getValue(RingPolynomial& p, Number& point, unsigned int modulo) {
	Number result(0);

	for (int i = 0; i < p.terms.size(); i++) {
		Number degree = p.terms[i].getDegree();		
		Number coefficient = p.terms[i].getCoefficient();
		Number power(1);

		for (int i = 0; degree > i; i++) {
			power = NumberMultiplication::run(power, point, modulo);
		}

		result = NumberAddition::run(result, NumberMultiplication::run(coefficient, power, modulo), modulo);
	}

	return result;
}