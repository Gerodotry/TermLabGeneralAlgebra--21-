#ifndef LAB_RINGPOLYNOMIAL_H
#define LAB_RINGPOLYNOMIAL_H

#include <vector>
#include "Polynomial.h"

class RingPolynomial: public Polynomial {
public:
    // TODO: Maybe, it is better to use templates for constructors
    RingPolynomial() = default;

    RingPolynomial(const std::initializer_list<PolynomialTerm>& terms);

    RingPolynomial(const std::vector<PolynomialTerm>& terms);

    RingPolynomial(const std::vector<std::string>& degrees, const std::vector<std::string>& coefficients);

    RingPolynomial(const std::vector<Number>& degrees, const std::vector<Number>& coefficients);

    virtual void toField(int modulo) override;
};

#endif //LAB_RINGPOLYNOMIAL_H
