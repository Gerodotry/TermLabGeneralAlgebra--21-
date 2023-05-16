#ifndef LAB_NUMBERDIVISION_H
#define LAB_NUMBERDIVISION_H

#include "utils/Number.h"

class NumberDivision {
public:
    static Number run(Number a, Number b, Number modulo);

private:
    static Number divide(Number& a, Number& b, Number& modulo);
};


#endif //LAB_NUMBERDIVISION_H
