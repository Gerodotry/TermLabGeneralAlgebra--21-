#ifndef LAB_NUMBERADDITION_H
#define LAB_NUMBERADDITION_H
#include "utils/Number.h"

class NumberAddition {
public:
    static Number run(Number a, Number b, Number modulo);

private:
    static Number add(Number& a, Number& b, Number& modulo);
};

#endif //LAB_NUMBERADDITION_H
