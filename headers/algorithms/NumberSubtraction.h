#ifndef LAB_NUMBERSUBTRACTION_H
#define LAB_NUMBERSUBTRACTION_H

#include "utils/Number.h"

class NumberSubtraction {
public:
    static Number run(Number a, Number b, unsigned int modulo) {
        if (a < b) {
            std::swap(a, b);
        }
        const std::vector<unsigned int>& big = a.digits, small = b.digits;
        bool borrow = false;
        Number difference;
        for (unsigned int i = 0; i < small.size(); i++) {
            unsigned int v = big[i] - small[i] - borrow;
            borrow = v >= modulo;
            difference.digits.push_back(v + (borrow ? modulo : 0));
        }
        for (unsigned int i = small.size(); i < big.size(); i++) {
            unsigned int v = big[i] - borrow;
            borrow = v >= modulo;
            difference.digits.push_back(v + (borrow ? modulo : 0));
        }
        return difference;
    }
};

#endif //LAB_NUMBERSUBTRACTION_H
