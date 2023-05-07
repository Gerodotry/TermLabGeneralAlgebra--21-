#ifndef LAB_NUMBER_H
#define LAB_NUMBER_H

#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include "Object.h"

class Number: public Object {
    friend class NumberAddition;
    friend class NumberSubtraction;
    friend class NumberMultiplication;
    friend class NumberDivision;
    friend class NumberRemainder;
    friend class PolynomialTerm;
public:
    Number() = default;

    explicit Number(const std::vector<unsigned int>& number);

    explicit Number(const std::string& number);

    explicit Number(unsigned int number);

    explicit Number(int number);

    unsigned int& operator [] (int i);

    unsigned int& operator [] (unsigned int i);

    unsigned int& operator [] (std::size_t i);

    bool operator == (const Number& other) const;

    bool operator == (const int& other) const;

    bool operator != (const Number& other) const;

    bool operator != (const int& other) const;

    bool operator > (const Number& other) const;

    bool operator >= (const Number& other) const;

    bool operator < (const Number& other) const;

    bool operator <= (const Number& other) const;

    Number& operator = (const Number& other);

    bool isZero();

    virtual std::string toString() override;

    std::string toString(bool abs);

    void toField(unsigned int modulo);

protected:
    bool isPositive = true;
    std::vector<unsigned int> digits;

    void simplify();

    int compareDigits(const Number& other) const;

    void digitalize(const std::string& string);
};

#endif //LAB_NUMBER_H
