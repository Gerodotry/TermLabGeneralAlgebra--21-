#include <stdexcept>
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberMultiplication.h"

Number NumberDivision::run(Number a, Number b, unsigned int modulo) {
    if (modulo) {
        a.toField(modulo);
        b.toField(modulo);
    }
    return divide(a, b, modulo);
}

Number NumberDivision::divide(const Number &a, const Number &b, unsigned int modulo) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    if (a < b) {
        return Number(0);
    }
    int i = b.digits.size();

    Number part;
    for (int j = 0; j < i; ++j) {
        part.digits.push_back(a.digits[j + a.digits.size() - i]);
    }

    std::vector<unsigned int> result;
    do {
        if (part < b) {
            if (i >= a.digits.size()) {
                break;
            } else {
                part.digits.insert(part.digits.begin(), a.digits[a.digits.size() - i - 1]);
                part.simplify();
            }
            i++;
        }
        while (part < b && i < a.digits.size()) {
            if (i >= a.digits.size()) {
                result.push_back(0);
                break;
            } else {
                result.push_back(0);
                part.digits.insert(part.digits.begin(), a.digits[a.digits.size() - i - 1]);
                part.simplify();
            }
            i++;
        }

        int j = 0;
        while (part >= b) {
            j++;
            part = NumberSubtraction::run(part, b, 0);
        }
        result.push_back(j);
    } while (i < a.digits.size());
    std::reverse(result.begin(), result.end());
    return Number(result);
}
