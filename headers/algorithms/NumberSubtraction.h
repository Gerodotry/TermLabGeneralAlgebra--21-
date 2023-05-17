#ifndef LAB_NUMBERSUBTRACTION_H
#define LAB_NUMBERSUBTRACTION_H

#include "utils/Number.h"

class NumberSubtraction {
public:
    static Number run(Number a, Number b, Number modulo);

private:
    static Number subtract(Number& a, Number& b, Number& modulo);
};

#endif //LAB_NUMBERSUBTRACTION_H
