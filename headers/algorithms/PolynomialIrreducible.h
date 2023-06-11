//
// Created by sofia on 11.06.2023.
//

#ifndef LAB_POLYNOMIALIRREDUCIBLE_H
#define LAB_POLYNOMIALIRREDUCIBLE_H

#include <vector>

using namespace std;

class PolynomialIrreducible {
    vector<int> power_mod(const vector<int>& a, const vector<int>& exp, const vector<int>& modulus);
    vector<int> reduce(const vector<int>& a, const vector<int>& b);
    vector<int> multiply(const vector<int>& a, const vector<int>& b);
public:
    bool test_irreducibility(const vector<int>& polynomial);
};

#endif //LAB_POLYNOMIALIRREDUCIBLE_H
