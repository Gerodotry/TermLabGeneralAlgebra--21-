#ifndef LAB_NUMBERDIVISION_H
#define LAB_NUMBERDIVISION_H

#include "utils/Number.h"

class NumberDivision {
public:
    static Number run(Number a, Number b, unsigned int modulo);

private:
    static Number divide(Number& a, Number& b, unsigned int modulo);
};


#endif //LAB_NUMBERDIVISION_H
