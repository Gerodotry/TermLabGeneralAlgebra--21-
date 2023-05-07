//
// Created by Sasha on 07.05.2023.
//

#ifndef LAB_DIVISION_H
#define LAB_DIVISION_H

#include <iostream>
#include <vector>

class Division {
public:
    static std::vector<int> run(std::vector<int> poly1, std::vector<int> poly2, int mod);
private:
    static int sub_poly(int *p, int *q, int len, int mod);

    static std::vector<int> division(std::vector<int> poly1, std::vector<int> poly2, int mod);

    static std::vector<int> divisionCoefs;
};


#endif //LAB_DIVISION_H
