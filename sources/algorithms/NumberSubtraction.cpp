#include "algorithms/NumberSubtraction.h"

Number NumberSubtraction::run(Number a, Number b, unsigned int modulo) {
    a.toField(modulo);
    b.toField(modulo);
    return subtract(a, b, modulo);
}

Number NumberSubtraction::subtract(Number& a, Number& b, unsigned int modulo) {
    Number difference = Number();
    bool borrow = false;
    int i = 0;
    for (; i < b.digits.size(); ++i) {
        int digitDifference;
        if (a.digits[i]) {
            digitDifference = int(a.digits[i] - b.digits[i] - borrow);
            borrow = digitDifference < 0;
        } else {
            digitDifference = int(modulo - b.digits[i] - borrow);
            borrow = true;
        }
        difference.digits.push_back(digitDifference + modulo * borrow);
    }
    while (i < a.digits.size()) {
        int digitDifference;
        if (a.digits[i]) {
            digitDifference = int(a.digits[i] - borrow);
            borrow = digitDifference < 0;
        } else {
            digitDifference = modulo - borrow;
            borrow = true;
        }
        difference.digits.push_back(digitDifference + modulo * borrow);
        ++i;
    }
    difference.toField(modulo);
    difference.simplify();
    return difference;
}