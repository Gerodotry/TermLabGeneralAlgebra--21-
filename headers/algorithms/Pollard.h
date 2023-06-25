#ifndef LAB_POLLARD_H
#define LAB_POLLARD_H

#include "utils/Number.h"
#include <vector>

class Pollard {
public:
    static std::vector<Number> run(Number a);

private:

    static void pollard_factorization(Number n, std::vector<Number> &factors);

    static bool is_prime(Number n);

    static Number pollard_rho(Number n);
};

#endif //LAB_POLLARD_H