#include <stdexcept>
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberMultiplication.h"

Number NumberDivision::run(Number a, Number b, unsigned int modulo) {
    a.toField(modulo);
    b.toField(modulo);
    return divide(a, b, modulo);
}

Number NumberDivision::divide(const Number& a, const Number& b, unsigned int modulo) {
    if (b.isZero()) {
        throw std::invalid_argument("Division by zero");
    }
    if (a < b) {
        return Number(0);
    }
    int i = int(b.digits.size() - 1);
    Number part(std::vector<unsigned int>(a.digits.rbegin(), a.digits.rbegin() + i+1));
    std::vector<unsigned int> result;
    while (i < a.digits.size()) {
        if (part < b) {
            i++;
            if (i >= a.digits.size()) {
                return Number(result);
            }
            else {
                part.digits.insert(part.digits.begin(), a.digits.end()[-i - 1]);
                part.simplify();
            }
        }
        while (part < b) {
            i++;
            if (i >= a.digits.size()) {
                result.push_back(0);
                return Number(result);
            }
            else {
                result.push_back(0);
                part.digits.insert(part.digits.begin(), a.digits.end()[-i - 1]);
                part.simplify();
            }
        }
        int j = 0;
        while (part >= b) {
            j++;
            part = NumberSubtraction::run(part, b, modulo);
        }
        result.push_back(j);
    }
    return Number(0);
}
