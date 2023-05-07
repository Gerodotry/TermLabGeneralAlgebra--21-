#ifndef LAB_NUMBERREMAINDER_H
#define LAB_NUMBERREMAINDER_H

#include "utils/Number.h"

class NumberRemainder {
public:
    static Number run(Number a, Number b, unsigned int modulo);

private:
    static Number remainder(Number& a, Number& b, unsigned int modulo);
};


#endif //LAB_NUMBERREMAINDER_H
