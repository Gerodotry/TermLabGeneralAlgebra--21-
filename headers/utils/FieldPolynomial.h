#ifndef LAB_FieldPolynomial_H
#define LAB_FieldPolynomial_H

#include "Polynomial.h"
#include "PolynomialTerm.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberMultiplication.h"

class FieldPolynomial : public Polynomial {
public:
    FieldPolynomial() = default;

    explicit FieldPolynomial(int n, int value = 0);

    FieldPolynomial(const std::initializer_list<PolynomialTerm> &terms);

    FieldPolynomial(const std::vector<PolynomialTerm> &terms);

    FieldPolynomial(const std::vector<std::string> &degrees, const std::vector<std::string> &coefficients);

    FieldPolynomial(const std::vector<Number> &degrees, const std::vector<Number> &coefficients);

    virtual void toField(int modulo) override;

    bool isZero();

private:
    int calculateBitsNumber(int number);

    static long long calculateU(long long R, long long module);

};

#endif //LAB_FieldPolynomial_H
