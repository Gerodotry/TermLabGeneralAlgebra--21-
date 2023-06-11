//
// Created by sofia on 11.06.2023.
//

#ifndef LAB_POLYNOMIALIRREDUCIBLE_H
#define LAB_POLYNOMIALIRREDUCIBLE_H

#include <vector>

using namespace std;

class PolynomialIrreducible {
    int polynomialDegree(const std::vector<int>& polynomial);
    std::vector<int> convolution(const std::vector<int>& a, const std::vector<int>& b);
    std::vector<int> polynomialMod(const std::vector<int>& dividend, const std::vector<int>& divisor);
public:
    bool isIrreducible(const std::vector<int>& polynomial, int fieldSize);
};

#endif //LAB_POLYNOMIALIRREDUCIBLE_H
