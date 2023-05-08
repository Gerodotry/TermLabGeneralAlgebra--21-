#include "algorithms/Pollard.h"
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberAddition.h"
#include "algorithms/NumberMultiplication.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberRemainder.h"

vector<Number> Naive::run(Number a, unsigned int modulo) {
    if (modulo) {
        a.toField(modulo);
    }
    return naive_factorization(a, modulo);
}

vector<Number> Naive::naive_factorization(Number& a,unsigned int modulo) 
{
    vector<Number> b;
    for (Number i = Number(2); i <= NumberMultiplication::run(a,a,modulo); NumberAddition::run(i,Number(1),modulo)) 
    {
        while (NumberRemainder::run(a,i,modulo) == Number(0)) {
            b.push_back(i);
            a = NumberSubtraction::run(a,i,modulo);
        }
    }
    if (a > Number(1)) {
        b.push_back(a);
    }
    return b;
}