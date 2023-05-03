#include "algorithms/Pollard.h"
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberAddition.h"
#include "algorithms/NumberGCD.h"
#include "algorithms/NumberMultiplication.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberRemainder.h"

vector<Number> Pollard::run(Number a, unsigned int modulo) {
    a.toField(modulo);
    return pollard_factorization(a, modulo);
}

vector<Number> Pollard::pollard_factorization(Number& a, unsigned int modulo)
{
    vector<Number> n;
    Number b = a;
    while(b > 1)
    {
        Number x = 2, y = 2, d = 1;
        while (d == 1) {
            x = NumberRemainder::run(NumberMultiplication::run(x,NumberAddition::run(x,1,modulo),modulo),b,modulo);
            y = NumberRemainder::run(NumberMultiplication::run(y,NumberAddition::run(y,1,modulo),modulo),b,modulo);
            y = NumberRemainder::run(NumberMultiplication::run(y,NumberAddition::run(y,1,modulo),modulo),b,modulo);
            d = NumberGCD::run(NumberDivision::run(x,y,modulo),b,modulo);
        }
        n.push_back(d);
        b = NumberSubtraction::run(b,d,modulo);
    }
    return n;
}