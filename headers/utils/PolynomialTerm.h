#ifndef LAB_POLYNOMIALTERM_H
#define LAB_POLYNOMIALTERM_H

#include <utility>

#include "Number.h"

class PolynomialTerm {
    friend class Polynomial;
public:
    PolynomialTerm();

    PolynomialTerm(const Number& degree, const Number& coefficient);

    PolynomialTerm(const int& degree, const int& coefficient);

    PolynomialTerm(const unsigned int& degree, const unsigned int& coefficient);

    PolynomialTerm(const std::string& degree, const std::string& coefficient);

    bool isZero() const;

    std::string toString() const;

private:
    std::string coeffToString() const;

protected:
    Number degree;
    Number coeff;

    void simplify(unsigned int modulo);
};


#endif //LAB_POLYNOMIALTERM_H