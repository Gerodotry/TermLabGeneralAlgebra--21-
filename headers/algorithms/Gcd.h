//
// Created by Sasha on 05.05.2023.
//

#ifndef LAB_GCD_H
#define LAB_GCD_H

#include <iostream>
#include <vector>

class Gcd {
public:
    static std::vector<int> run(std::vector<int> a, std::vector<int> b, int mod);

    static int sub_poly(int *p, int *q, int len, int mod);

    static std::vector<int> subtract_polys(std::vector<int> poly1, std::vector<int> poly2, int mod);

    static std::vector<int> gcd(std::vector<int> a, std::vector<int> b, int mod);

    static std::vector<int> division(std::vector<int> poly1, std::vector<int> poly2, int mod);

    static std::vector<int> divisionCoefs;
};


#endif //LAB_GCD_H
