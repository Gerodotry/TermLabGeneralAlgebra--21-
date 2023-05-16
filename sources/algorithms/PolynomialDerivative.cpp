#include "algorithms/PolynomialDerivative.h"

RingPolynomial PolynomialDerivative::run(RingPolynomial p, unsigned int modulo) {
	if (modulo) {
		p.toField(modulo);		
	}

	return getDerivative(p, modulo);
}

RingPolynomial PolynomialDerivative::getDerivative(RingPolynomial& p, unsigned int modulo) {
	RingPolynomial derivative;

	for (int i = 0; i < p.terms.size(); i++) {
		Number degree = p.terms[i].getDegree();
		if (degree == 0) continue;
		Number coefficient = p.terms[i].getCoefficient();
		Number derivativeCoefficient = NumberMultiplication::run(degree, coefficient, modulo);
		Number derivativeDegree = NumberSubtraction::run(degree, Number(1), 0);
		PolynomialTerm term({ derivativeDegree, derivativeCoefficient });
		derivative.terms.push_back(term);
	}

	return derivative;
}