#ifndef LAB_NUMBER_H
#define LAB_NUMBER_H

#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

class Number {
    friend class NumberAddition;
    friend class NumberMultiplication;
    friend class NumberSubtraction;
    friend class PolynomialTerm;
public:
    Number() = default;

    explicit Number(const std::string& string);

    explicit Number(unsigned int num);

    explicit Number(int num);

    unsigned int& operator [] (int i);

    unsigned int& operator [] (unsigned int i);

    unsigned int& operator [] (std::size_t i);

    bool operator == (const Number& other) const;

    bool operator != (const Number& other) const;

    bool operator > (const Number& other) const;

    bool operator >= (const Number& other) const;

    bool operator < (const Number& other) const;

    bool operator <= (const Number& other) const;

    bool isZero() const;

    std::string toString() const;

protected:
    bool isPositive = true;
    std::vector<unsigned int> digits;

    void simplify();

    void toField(unsigned int modulo);

    int compareDigits(const Number& other) const;

    void digitalize(const std::string& str);
};

#endif //LAB_NUMBER_H
