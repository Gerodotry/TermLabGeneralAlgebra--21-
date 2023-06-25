#include "algorithms/Pollard.h"
#include "algorithms/NumberGCD.h"
#include <iostream>
#include <ctime>

std::vector<Number> Pollard::run(Number a) {
    std::vector<Number> factors;

    while (factors.empty()){
        pollard_factorization(a, factors);
    }

    return factors;
}

void Pollard::pollard_factorization(Number n, std::vector<Number>& factors) {
    if (n == 1)
        return;

    if (is_prime(n)) {
        factors.push_back(n);
        return;
    }

    Number factor = pollard_rho(n);
    pollard_factorization(factor, factors);
    pollard_factorization(n / factor, factors);
}

bool Pollard::is_prime(Number n) {
    if (n <= 1)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (Number i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

Number Pollard::pollard_rho(Number n) {
    if (n == 1)
        return n;

    if (n % 2 == 0)
        return 2;

    srand(time(NULL));

    Number x = rand() % (n - 2) + 2;
    Number y = x;
    Number c = rand() % (n - 1) + 1;
    Number d = 1;

    while (d == 1) {
        x = (x * x + c) % n;
        y = (y * y + c) % n;
        y = (y * y + c) % n;
        d = NumberGCD::run((x - y).findAbs(), n, UINT_MAX);

        if (d == n)
            return pollard_rho(n);
    }

    return d;
}

