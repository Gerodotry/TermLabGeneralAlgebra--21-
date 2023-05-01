#ifndef LAB_NUMBERGCD_H
#define LAB_NUMBERGCD_H

#include "utils/Number.h"

class NumberGCD {
public:
    static Number run(Number a, Number b, unsigned int modulo);

private:
    static Number gcd(Number& a, Number& b, unsigned int modulo);
};


#endif //LAB_NUMBERGCD_H
