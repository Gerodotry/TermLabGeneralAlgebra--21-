#ifndef LAB_POLYNOMIALTERM_H
#define LAB_POLYNOMIALTERM_H

#include <utility>
#include <stdexcept>
#include <initializer_list>
#include "Number.h"

class PolynomialTerm {
    friend class Polynomial;
public:
    PolynomialTerm();

    PolynomialTerm(const std::initializer_list<Number>& values);

    PolynomialTerm(const std::initializer_list<int>& values);

    PolynomialTerm(const std::initializer_list<unsigned int>& values);

    PolynomialTerm(const std::initializer_list<std::string>& values);

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
    Number coefficient;

    void toField(unsigned int modulo);
};

#endif //LAB_POLYNOMIALTERM_H
