#ifndef LAB_POLYNOMIALTERM_H
#define LAB_POLYNOMIALTERM_H

#include <utility>
#include "Number.h"

class PolynomialTerm {
    friend class RingPolynomial;
public:
    Number degree;
    Number coefficient;

    PolynomialTerm();

    PolynomialTerm(Number degree, Number coefficient);

    PolynomialTerm(int degree, int coefficient);

    PolynomialTerm(unsigned int degree, unsigned int coefficient);

    PolynomialTerm(const std::string& degree, const std::string& coefficient);

    Number getDegree() const;

    Number getCoefficient() const;

    void setDegree(const Number& degree);

    void setCoefficient(const Number& coefficient);

    bool isZero();

    std::string toString();

    void toField(unsigned int modulo, bool isRing);
private:
    std::string coeffToString();
};

#endif //LAB_POLYNOMIALTERM_H
