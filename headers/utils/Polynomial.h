//
// Created by Dklishch on 5/7/2023.
//

#ifndef LAB_POLYNOMIAL_H
#define LAB_POLYNOMIAL_H

#include <vector>
#include "PolynomialTerm.h"

class Polynomial: public Object {
public:
    std::vector<PolynomialTerm> terms;

    Polynomial() = default;

    Polynomial(const std::initializer_list<PolynomialTerm>& terms);

    Polynomial(const std::vector<PolynomialTerm>& terms);

    Polynomial(const std::vector<std::string>& degrees, const std::vector<std::string>& coefficients);

    Polynomial(std::vector<Number> degrees, std::vector<Number> coefficients);

    virtual std::string toString() override;

    virtual void toField(unsigned int modulo) = 0;

    Polynomial& operator=(const Polynomial &polynomial);

    void sortByDegree(bool ascending = true);

    void sortByCoefficient(bool ascending = true);

    void dropZeroes();
};

#endif //LAB_POLYNOMIAL_H

