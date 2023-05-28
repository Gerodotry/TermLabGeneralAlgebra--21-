#ifndef LAB_GROUPELEMENTORDER_H
#define LAB_GROUPELEMENTORDER_H

#include "utils/Number.h"
#include "NumberMultiplication.h"

class GroupElementOrder {
public:
    static long long  run(Number a, Number modulo);

private:
    static long long  findOrder(Number& a, Number& modulo, long long max_iterations);
};


#endif //LAB_GROUPELEMENTORDER_H
