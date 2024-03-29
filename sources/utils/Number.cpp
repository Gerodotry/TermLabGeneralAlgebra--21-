#include <stdexcept>
#include "utils/Number.h"
#include "algorithms/NumberSubtraction.h"
#include "algorithms/NumberMultiplication.h"
#include "algorithms/NumberRemainder.h"

Number::Number(const std::vector<unsigned int>& number) {
    digits = number;
}

Number::Number(const std::string &number) {
    if (number[0] == '-') {
        isPositive = false;
        digitalize(number.substr(1));
    } else {
        digitalize(number);
    }
    simplify();
}

Number::Number(unsigned int number) {
    while (number > 0) {
        digits.push_back(number % 10);
        number /= 10;
    }
    simplify();
}

Number::Number(int number) {
    if (number < 0) {
        isPositive = false;
        number = abs(number);
    }
    while (number > 0) {
        digits.push_back(number % 10);
        number /= 10;
    }
    simplify();
}

unsigned int &Number::operator [] (int i) {
    return digits[i];
}

unsigned int &Number::operator [] (unsigned int i) {
    return digits[i];
}

unsigned int &Number::operator [] (std::size_t i) {
    return digits[i];
}

bool Number::operator == (const Number &other) const {
    return digits == other.digits;
}


bool Number::operator == (const int &other) const {
    if (isPositive != (other >= 0)) {
        return false;
    }
    // Check if the number of digits is the same
    int numDigits = 0;
    int otherCopy = other;
    while (otherCopy != 0) {
        numDigits++;
        otherCopy /= 10;
    }
    if (digits.size() != numDigits) {
        return false;
    }
    otherCopy = other;
    for (int i = int(digits.size() - 1); i >= 0; --i) {
        int digit = other % 10;
        if (digits[i] != abs(digit)) {
            return false;
        }
        otherCopy /= 10;
    }
    return true;
}

bool Number::operator != (const int &other) const {
    return !(*this == other);
}

bool Number::operator > (const Number &other) const {
    return compareDigits(other) > 0;
}

bool Number::operator != (const Number &other) const {
    return !(*this == other);
}

bool Number::operator >= (const Number &other) const {
    return compareDigits(other) >= 0;
}

bool Number::operator < (const Number &other) const {
    return compareDigits(other) < 0;
}

bool Number::operator <= (const Number &other) const {
    return compareDigits(other) <= 0;
}

Number &Number::operator = (const Number &other) {
    if (this == &other) {
        return *this;
    }
    isPositive = other.isPositive;
    digits = other.digits;
    return *this;
}

bool Number::isZero() {
    simplify();
    return digits.empty();
}

std::string Number::toString(bool abs) {
    if (isZero()) {
        return "0";
    }
    std::string str(digits.size(), '0');
    std::transform(digits.rbegin(), digits.rend(), str.begin(),
                   [](unsigned int d) { return d + '0'; });
    return (isPositive || abs) ? str : ("-" + str);
}

void Number::simplify() {
    while (!digits.empty() && digits.back() == 0) {
        digits.pop_back();
    }
}

void Number::toField(unsigned int modulo) {
    // Compute the value of the number in the given field
    long long value = 0, pow = 1;
    for (int i = 0; i < digits.size(); ++i) {
        value = (value + pow * digits[i]) % modulo;
        pow = (pow * 10) % modulo;
    }
    digits.clear();
    if (!value) {
        digits.push_back(0);
        return;
    }
    if (!isPositive) {
        value = modulo - value;
        isPositive = true;
    }
    // Convert the value back to digits
    int nDigits = int(floor(log10(value)) + 1);
    for (int i = 0; i < nDigits; ++i) {
        digits.push_back(value % 10);
        value /= 10;
    }
}

void Number::toField(const Number &modulo) {
    *this = *this % modulo;
}

int Number::compareDigits(const Number &other) const {
    if (isPositive != other.isPositive) {
        // If the signs are different, return -1 if this number is negative,
        // and return 1 if this number is positive.
        return isPositive ? 1 : -1;
    }
    // If the signs are the same, compare the absolute values of the numbers.
    if (digits.size() != other.digits.size()) {
        if (isPositive) {
            return digits.size() < other.digits.size() ? -1 : 1;
        } else {
            return digits.size() < other.digits.size() ? 1 : -1;
        }
    }
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] < other.digits[i]) {
            return isPositive ? -1 : 1;
        }
        if (digits[i] > other.digits[i]) {
            return isPositive ? 1 : -1;
        }
    }
    return 0;
}

void Number::digitalize(const std::string &string) {
    digits = std::vector<unsigned int>(string.size());
    for (size_t i = 0; i < string.size(); ++i) {
        digits[i] = string[string.size() - 1 - i] - '0';
    }
    simplify();
}

std::string Number::toString() {
    return toString(false);
}

Number::Number(long long number) {
    while (number > 0) {
        digits.push_back(number % 10);
        number /= 10;
    }
    simplify();
}

bool Number::operator>(long long other) const {
    return *this > Number(other);
}

bool Number::operator>=(long long other) const {
    return *this >= Number(other);
}

bool Number::operator<(long long other) const {
    return *this < Number(other);
}

bool Number::operator<=(long long other) const {
    return *this <= Number(other);
}

long long Number::get() const {
    long long value = 0;
    for (int i = digits.size() - 1; i >= 0; --i) {
        value = value * 10 + digits[i];
    }
    if (!isPositive) value *= -1;
    return value;
}

Number operator/(Number a, Number b) {
    if (b.isZero()) {
        throw std::invalid_argument("Division by zero");
    }

    bool isNegative = !a.isPositive || !b.isPositive;

    a.isPositive = true;
    b.isPositive = true;

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
            part = part - b;
        }
        result.push_back(j);
    } while (i < a.digits.size());
    std::reverse(result.begin(), result.end());

    Number numberResult(result);

    if (isNegative) {
        numberResult.isPositive = false;
    }

    return numberResult;
}

Number operator%(Number a, Number b) {
    if (b.isZero()) {
        throw std::invalid_argument("Division by zero");
    }

    Number quotient, remainder;
    quotient = a / b;

    remainder = quotient * b;
    remainder = a - remainder;

    return remainder;
}

Number operator+(Number a, Number b) {
    Number result;
    std::size_t minSize = std::min(a.digits.size(), b.digits.size());
    bool carry = false;
    for (std::size_t i = 0; i < minSize; i++) {
        unsigned int v = a.digits[i] + b.digits[i] + carry;
        carry = v / 10;
        result.digits.emplace_back(v % 10);
    }
    Number longer = a.digits.size() > b.digits.size() ? a : b;
    std::size_t i = minSize;
    while (i < longer.digits.size()) {
        unsigned int v = longer[i] + carry;
        carry = v / 10;
        result.digits.emplace_back(v % 10);
        i++;
    }
    if (carry) {
        result.digits.emplace_back(1);
    }
    return result;
}

Number operator-(Number a, Number b) {
    if (a.isPositive && !b.isPositive) {
        b.isPositive = true;
        return a + b;
    }

    if (!a.isPositive && b.isPositive) {
        a.isPositive = true;
        Number result = a + b;
        result.isPositive = false;
        return result;
    }

    if (!a.isPositive && !b.isPositive) {
        std::swap(a, b);
        a.isPositive = true;
        b.isPositive = true;
    }

    Number result;

    if (a < b) {
        std::swap(a, b);
        result.isPositive = false;
    }

    result.digits.resize(a.digits.size());
    int borrow = 0;
    for (size_t i = 0; i < a.digits.size(); i++) {
        int digit = a.digits[i];
        if (i < b.digits.size()) {
            digit -= b.digits[i];
        }
        digit -= borrow;
        if (digit >= 0) {
            borrow = 0;
        } else {
            borrow = 1;
            digit += 10;
        }
        result.digits[i] = digit;
    }

    result.simplify();
    return result;
}

Number operator*(Number a, Number b) {
    Number product;
    std::size_t aSize = a.digits.size();
    std::size_t bSize = b.digits.size();
    product.digits.resize(aSize + bSize);
    for (std::size_t i = 0; i < aSize; i++) {
        unsigned int carry = 0;
        for (std::size_t j = 0; j < bSize; j++) {
            huge temp = huge(a.digits[i]) * huge(b.digits[j]) + huge(product.digits[i+j]) + huge(carry);
            product.digits[i+j] = temp % 10;
            carry = temp / 10;
        }
        if (carry > 0) {
            product.digits[i + bSize] += carry;
        }
    }

    product.simplify();

    if ((a.isPositive + b.isPositive) % 2) {
        product.isPositive = false;
    }
    return product;
}

Number Number::findAbs() const {
    Number result = *this;
    result.isPositive = true;
    return result;
}

