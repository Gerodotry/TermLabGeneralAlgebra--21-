//
// Created by Sasha on 07.05.2023.
//

#ifndef LAB_REMAINDER_H
#define LAB_REMAINDER_H

#include <iostream>
#include <vector>

class Remainder {
public:
    static std::vector<int> run(std::vector<int> poly1, std::vector<int> poly2, int mod);
private:
    static int sub_poly(int *p, int *q, int len, int mod);

    static std::vector<int> subtract_polys(const std::vector<int>& poly1, const std::vector<int>& poly2, int mod);
};


#endif //LAB_REMAINDER_H
