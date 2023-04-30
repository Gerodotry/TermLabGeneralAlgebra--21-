#ifndef LAB_NUMBERADDITION_H
#define LAB_NUMBERADDITION_H
#include "utils/Number.h"

class NumberAddition {
public:
    static Number run(Number a, Number b, unsigned int modulo);

    static Number add(const Number& a, const Number& b, unsigned int modulo);
};

#endif //LAB_NUMBERADDITION_H
