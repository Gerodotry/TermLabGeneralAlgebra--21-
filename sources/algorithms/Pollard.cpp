#include "algorithms/Pollard.h"
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberAddition.h"
#include "algorithms/NumberGCD.h"
#include "algorithms/NumberMultiplication.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberRemainder.h"

vector<Number> Pollard::run(Number a, unsigned int modulo) {
    if (modulo) {
        a.toField(modulo);
    }
    return pollard_factorization(a, modulo);
}

vector<Number> Pollard::pollard_factorization(Number& a, unsigned int modulo)
{
    vector<Number> n;
    Number b = a;
    while(b > Number(1))
    {
        Number x = Number(2);
        Number y = Number(2);
        Number d = Number(2);
        while (d == Number(1)) {
            x = NumberRemainder::run(NumberMultiplication::run(x,NumberAddition::run(x,Number(1),modulo),modulo),b,modulo);
            y = NumberRemainder::run(NumberMultiplication::run(y,NumberAddition::run(y,Number(1),modulo),modulo),b,modulo);
            y = NumberRemainder::run(NumberMultiplication::run(y,NumberAddition::run(y,Number(1),modulo),modulo),b,modulo);
            d = NumberGCD::run(NumberDivision::run(x,y,modulo),b,modulo);
        }
        n.push_back(d);
        b = NumberSubtraction::run(b,d,modulo);
    }
    return n;
}