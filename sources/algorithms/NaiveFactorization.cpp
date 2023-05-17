#include <algorithms/NumberGCD.h>
#include <algorithms/NumberRemainder.h>
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberAddition.h"
#include "algorithms/NaiveFactorization.h"

std::vector<Number> NaiveFactorization::run(Number a) {
    return naive_factorization(a);
}

std::vector<Number> NaiveFactorization::naive_factorization(Number& n) {
    std::vector<Number> factors;

    if (!n.isPositive){
        factors.push_back(n);
        return factors;
    }

    for (Number i = Number(2); i <= n / i; i = i + Number(1)) {
        while ((n % i).isZero()) {
            factors.push_back(i);
            n = n / i;
        }
    }

    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}



