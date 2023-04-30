#ifndef LAB_NUMBERMULTIPLICATION_H
#define LAB_NUMBERMULTIPLICATION_H

#include "utils/Number.h"
#include "NumberAddition.h"

using std::vector;
using huge = unsigned long long int;

class NumberMultiplication {
public:
    static Number run(Number a, Number b, unsigned int modulo);

    static Number multiply(const Number& a, const Number& b, unsigned int modulo);
};

#endif //LAB_NUMBERMULTIPLICATION_H
