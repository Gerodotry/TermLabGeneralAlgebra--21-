#ifndef LAB_NUMBERSUBTRACTION_H
#define LAB_NUMBERSUBTRACTION_H

#include "utils/Number.h"

class NumberSubtraction {
public:
    static Number run(Number a, Number b, unsigned int modulo);

private:
    static Number subtract(Number& a, Number& b, unsigned int modulo);
};

#endif //LAB_NUMBERSUBTRACTION_H
