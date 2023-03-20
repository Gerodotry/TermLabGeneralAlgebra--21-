//
// Created by Ihor on 20.03.2023.
//

#ifndef LAB_NUMBERMULTIPLICATION_H
#define LAB_NUMBERMULTIPLICATION_H

#include "utils/Number.h"

using std::vector;

class NumberMultiplication {
public:
    static Number run(Number a, Number b, unsigned int modulo) {
        vector<unsigned int> product(a.getSize() + b.getSize());
        for (unsigned int i = 0; i < a.getSize(); i++) {
            for (unsigned int j = 0; j < b.getSize(); j++) {
                product[i+j] += static_cast<unsigned int>(a[i]) * static_cast<unsigned int>(b[j]);
            }
        }
        vector<unsigned int> resultDigits;
        unsigned int carry = 0;
        for (unsigned int i : product) {
            carry += i;
            resultDigits.push_back(carry % modulo);
            carry /= modulo;
        }
        Number result(resultDigits);
        return result.simplify();
    }
 };

#endif //LAB_NUMBERMULTIPLICATION_H
