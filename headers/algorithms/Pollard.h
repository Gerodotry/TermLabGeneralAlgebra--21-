#ifndef POLLARD_H
#define POLLARD_H

#include <vector>
#include <map>

class  PollardFactorization
{
public:
    /**
     * @brief factorize use the Rho-Pollard's algo.
     * @param number a number to take prime numbers of.
     * @return a vector of prime numbers
     */
    static std::map<long long, int> factorize(long long number);
};

#endif // POLLARDFACTORIZATION_H