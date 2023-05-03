#ifndef LAB_RINGPOLYNOMIAL_H
#define LAB_RINGPOLYNOMIAL_H

#include <vector>
#include "PolynomialTerm.h"

class RingPolynomial: public Object {
    friend class PolynomialTerm;
    friend class PolynomialAddition;
    friend class PolynomialSubtraction;
    friend class PolynomialMultiplication;

public:
    // TODO: Maybe, it is better to use templates for constructors
    RingPolynomial() = default;

    RingPolynomial(const std::initializer_list<PolynomialTerm>& terms);

    RingPolynomial(const std::vector<std::string>& degrees, const std::vector<std::string>& coefficients);

    RingPolynomial(std::vector<Number> degrees, std::vector<Number> coefficients);

    template<typename T>
    RingPolynomial(std::vector<T> degrees, std::vector<T> coefficients);

    virtual std::string toString() override;

    RingPolynomial& operator = (const RingPolynomial& polynomial);
protected:
    std::vector<PolynomialTerm> terms;

    void toField(unsigned int modulo);

    void sortByDegree(bool ascending = true);

    void sortByCoefficient(bool ascending = true);

private:
    void dropZeroes();
};

#endif //LAB_RINGPOLYNOMIAL_H
