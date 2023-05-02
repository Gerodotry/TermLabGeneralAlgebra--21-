#include <stdexcept>
#include "algorithms/NumberDivision.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberMultiplication.h"

Number NumberDivision::run(Number a, Number b, unsigned int modulo) {
    a.toField(modulo);
    b.toField(modulo);
    return divide(a, b, modulo);
}

Number NumberDivision::divide(const Number &dividend, const Number &divisor, unsigned int modulo) {
    // Check for division by zero
    if (divisor.isZero()) {
        throw std::invalid_argument("Division by zero");
    }

    // Initialize quotient and remainder
    Number quotient, remainder;
    quotient.digits.resize(dividend.digits.size());

    // Find the most significant non-zero digit of the divisor
    int nonZeroDigitIndex = int(divisor.digits.size() - 1);
    while (nonZeroDigitIndex >= 0 && divisor.digits[nonZeroDigitIndex] == 0) {
        nonZeroDigitIndex--;
    }

    // Perform long division
    for (int i = int(dividend.digits.size() - 1); i >= 0; i--) {
        remainder.digits.insert(remainder.digits.begin(), dividend.digits[i]);
        remainder.toField(modulo);

        // Find the most significant non-zero digit of the remainder
        int nonZeroRemainderIndex = int(remainder.digits.size() - 1);
        while (nonZeroRemainderIndex >= 0 && remainder.digits[nonZeroRemainderIndex] == 0) {
            nonZeroRemainderIndex--;
        }

        // If the divisor is greater than the remainder, skip this digit
        if (nonZeroDigitIndex > nonZeroRemainderIndex) {
            quotient.digits[i] = 0;
            continue;
        }

        // Perform the division for this digit
        unsigned int temp = 0;
        while (nonZeroDigitIndex <= nonZeroRemainderIndex) {
            unsigned int quotientDigit = remainder.digits[nonZeroRemainderIndex] / divisor.digits[nonZeroDigitIndex];
            quotient.digits[i] += int(quotientDigit * pow(10, nonZeroRemainderIndex - nonZeroDigitIndex));
            temp = quotientDigit * divisor.digits[nonZeroDigitIndex];
            nonZeroRemainderIndex--;
            while (nonZeroRemainderIndex >= 0 && remainder.digits[nonZeroRemainderIndex] == 0) {
                nonZeroRemainderIndex--;
            }
        }

        // Subtract the product of the quotient digit and the divisor from the remainder
        Number tempNumber;
        tempNumber.digits.push_back(temp);
        remainder = NumberSubtraction::run(remainder, NumberMultiplication::run(tempNumber, divisor, modulo), modulo);
    }

    // Remove leading zeros from the quotient
    while (quotient.digits.size() > 1 && quotient.digits.back() == 0) {
        quotient.digits.pop_back();
    }

    quotient.toField(modulo);
    return quotient;
}

