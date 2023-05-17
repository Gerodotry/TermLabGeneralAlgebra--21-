//
// Created by mac on 08.05.2023.
//

#ifndef LAB_INVERSE_H
#define LAB_INVERSE_H
#include "utils/Number.h"

class Inverse {
public:
    static Number run(Number a, Number modulo);
private:
    static Number inverse(Number& a, Number& modulo);
};
#endif //LAB_INVERSE_H
