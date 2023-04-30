#ifndef LAB_POLYNOMIAL_H
#define LAB_POLYNOMIAL_H

#include <vector>
#include "PolynomialTerm.h"

class Polynomial {
    friend class PolynomialTerm;
    friend class PolynomialAddition;
    friend class PolynomialSubtraction;
    friend class PolynomialMultiplication;

public:
    // TODO: Maybe, it is better to use templates for constructors
    Polynomial() = default;

    Polynomial(const std::initializer_list<PolynomialTerm>& terms);

    Polynomial(std::vector<Number> degrees, std::vector<Number> coefficients);

    template<typename T>
    Polynomial(std::vector<T> degrees, std::vector<T> coefficients);

    std::string toString();

protected:
    std::vector<PolynomialTerm> terms;

    void toField(unsigned int modulo);

    void sortByDegree(bool ascending = true);

    void sortByCoefficient(bool ascending = true);

private:
    void dropZeroes();
};

#endif //LAB_POLYNOMIAL_H