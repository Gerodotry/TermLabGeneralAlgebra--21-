#ifndef LAB_POLYNOMIALTERM_H
#define LAB_POLYNOMIALTERM_H

#include <utility>

#include "Number.h"

class PolynomialTerm {
    friend class Polynomial;
public:
    PolynomialTerm();

    PolynomialTerm(const Number& degree, const Number& coefficient);

    PolynomialTerm(int degree, int coefficient);

    PolynomialTerm(unsigned int degree, unsigned int coefficient);

    PolynomialTerm(const std::string& degree, const std::string& coefficient);

    Number getDegree() const;

    Number getCoefficient() const;

    void setDegree(const Number& degree);

    void setCoefficient(const Number& coefficient);

    bool isZero() const;

    std::string toString() const;

private:
    std::string coeffToString() const;

protected:
    Number degree;
    Number coeff;

    void toField(unsigned int modulo);
};

#endif //LAB_POLYNOMIALTERM_H
