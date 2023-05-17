
#ifndef LAB_TRUEDIVISION_H
#define LAB_TRUEDIVISION_H
#include "utils/Number.h"

class Truedivision {
public:
    static Number run(Number a, Number b, Number modulo);

private:
    static Number tdivide(Number& a, Number& b, Number& modulo);
};

#endif //LAB_TRUEDIVISION_H
