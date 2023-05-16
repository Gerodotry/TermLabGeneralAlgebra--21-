#ifndef LAB_NUMBERREMAINDER_H
#define LAB_NUMBERREMAINDER_H

#include "utils/Number.h"

class NumberRemainder {
public:
    static Number run(Number a, Number b, Number modulo);

private:
    static Number remainder(Number& a, Number& b, Number& modulo);
};


#endif //LAB_NUMBERREMAINDER_H
