#include "algorithms/NumberDivision.h"
#include "algorithms/NumberAddition.h"
#include "algorithms/NumberMultiplication.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberRemainder.h"
#include "algorithms/NaiveFactorization.h"

std::vector<Number> NaiveFactorization::run(Number a, unsigned int modulo) {
    if (modulo) {
        a.toField(modulo);
    }
    return naive_factorization(a, modulo);
}

std::vector<Number> NaiveFactorization::naive_factorization(Number &a, unsigned int modulo) {
    std::vector<Number> b;
    for (Number i = Number(2); i <= NumberMultiplication::run(a, a, modulo) && !a.isZero(); i = NumberAddition::run(i, Number(1), modulo)) {
        Number R = NumberRemainder::run(a, i, modulo);
        while (R.isZero()) {
            b.push_back(i);
            a = NumberSubtraction::run(a, i, modulo);
            R = NumberRemainder::run(a, i, modulo);
            if (a.isZero()) break;
        }
    }
    if (a > Number(1)) {
        b.push_back(a);
    }
    return b;
}