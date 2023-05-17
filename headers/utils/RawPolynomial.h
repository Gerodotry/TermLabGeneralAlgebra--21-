//
// Created by Dklishch on 5/8/2023.
//

#ifndef LAB_RAWPOLYNOMIAL_H
#define LAB_RAWPOLYNOMIAL_H

#include <vector>
#include "Object.h"

class RawPolynomial: public Object {
public:
    std::vector<int> coefficients;

    RawPolynomial();

    RawPolynomial(const std::vector<int>& coefficients);

    RawPolynomial(const std::vector<std::string>& degrees, const std::vector<std::string>& coefs);

    RawPolynomial(const std::vector<int>& degrees, const std::vector<int>& coefs);

    std::string toString() override;

    RawPolynomial& operator=(const RawPolynomial& polynomial);
private:
    void add(const std::vector<int>& degrees, const std::vector<int>& coefs);
};


#endif //LAB_RAWPOLYNOMIAL_H
