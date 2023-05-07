#ifndef LAB_FieldPolynomial_H
#define LAB_FieldPolynomial_H

#include "Polynomial.h"
#include "PolynomialTerm.h"

class FieldPolynomial: public Polynomial {
public:
    FieldPolynomial() = default;

    FieldPolynomial(const std::initializer_list<PolynomialTerm>& terms);

    FieldPolynomial(const std::vector<PolynomialTerm>& terms);

    FieldPolynomial(const std::vector<std::string>& degrees, const std::vector<std::string>& coefficients);

    FieldPolynomial(const std::vector<Number>& degrees, const std::vector<Number>& coefficients);

    virtual void toField(unsigned int modulo) override;
};

#endif //LAB_FieldPolynomial_H
