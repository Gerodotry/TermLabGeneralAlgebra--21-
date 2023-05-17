#ifndef LAB_NUMBERGCD_H
#define LAB_NUMBERGCD_H

#include "utils/Number.h"

class NumberGCD {
public:
    static Number run(Number a, Number b, Number modulo);

private:
    static Number gcd(Number& a, Number& b, Number& modulo);
};


#endif //LAB_NUMBERGCD_H
