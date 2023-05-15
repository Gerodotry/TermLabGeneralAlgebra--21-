﻿#ifndef LAB_POLLARD_H
#define LAB_POLLARD_H

#include "utils/Number.h"
#include <vector>

class Pollard {
public:
    static std::vector<Number> run(Number a);

private:
    static std::vector<Number> pollard_factorization(Number a);

    static Number sub(Number x, Number y);
};

#endif //LAB_POLLARD_H