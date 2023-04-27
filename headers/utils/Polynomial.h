#ifndef LAB_POLYNOMIAL_H
#define LAB_POLYNOMIAL_H

#include <vector>
#include "PolynomialTerm.h"

class Polynomial {
    friend class PolynomialTerm;

public:
    // TODO: Maybe, it is better to use templates for constructors
    Polynomial() = default;

    explicit Polynomial(const std::vector<PolynomialTerm>& terms);

    Polynomial(std::vector<Number> degrees, std::vector<Number> coefficients);

    Polynomial(std::vector<int> degrees, std::vector<int> coefficients);

    Polynomial(std::vector<unsigned int> degrees, std::vector<unsigned int> coefficients);

    Polynomial(std::vector<std::string> degrees, std::vector<std::string> coefficients);

    std::string toString();

private:
    void dropZeroes();

protected:
    std::vector<PolynomialTerm> terms;

    void toField(unsigned int modulo);
};


#endif //LAB_POLYNOMIAL_H
