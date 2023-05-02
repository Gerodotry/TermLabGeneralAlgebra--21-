#ifndef LAB_NAIVE_H
#define LAB_NAIVE_H

#include "utils/Number.h"
#include <vector>

class Naive {
public:
    static vector<Number> run(Number a, unsigned int modulo);

private:
    static vector<Number> naive_factorization(Number& a,unsigned int modulo);

#endif //LAB_NAIVE_H