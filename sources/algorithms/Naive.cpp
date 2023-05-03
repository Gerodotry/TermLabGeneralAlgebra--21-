#include "algorithms/Pollard.h"
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberAddition.h"
#include "algorithms/NumberMultiplication.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberRemainder.h"

vector<Number> Naive::run(Number a, unsigned int modulo) {
    a.toField(modulo);
    return naive_factorization(a, modulo);
}

vector<Number> Naive::naive_factorization(Number& a,unsigned int modulo) {
    vector<Number> b;
    for (Number i = 2; i <= NumberMultiplication::run(a,a,modulo); i++) {
        while (NumberRemainder::run(a,i,modulo) == 0) {
            b.push_back(i);
            n = NumberSubtraction::run(n,i,modulo);
        }
    }
    if (a > 1) {
        b.push_back(a);
    }
    return b;
}