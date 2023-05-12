#ifndef LAB_NAIVEFACTORIZATION_H
#define LAB_NAIVEFACTORIZATION_H

#include "utils/Number.h"
#include <vector>

class NaiveFactorization {
public:
    static std::vector<Number> run(Number a);

private:
    static std::vector<Number> naive_factorization(Number &a);
};

#endif //LAB_NAIVEFACTORIZATION_H