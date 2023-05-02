#include "../../headers/utils/Number.h"

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
    for (int i = int(digits.size() - 1); i >= 0; i--) {
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

bool Number::isZero() const {
    return digits.empty();
}

std::string Number::toString(bool abs) const {
    if (isZero()) {
        return "0";
    }
    std::string str(digits.size(), '0');
    std::transform(digits.rbegin(), digits.rend(), str.begin(),
                   [](unsigned int d) { return d + '0'; });
    return (isPositive || abs) ? str : ("-" + str);
}

void Number::simplify() {
    if (isZero()) {
        isPositive = true;
    }
    while (!digits.empty() && digits.back() == 0) {
        digits.pop_back();
    }
}

void Number::toField(unsigned int modulo) {
    // Compute the value of the number in the given field
    unsigned int value = 0;
    for (int i = int(digits.size() - 1); i >= 0; --i) {
        value = (value * 10 + digits[i]) % modulo;
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

int Number::compareDigits(const Number &other) const {
    if (isPositive != other.isPositive) {
        // If the signs are different, return -1 if this number is negative,
        // and return 1 if this number is positive.
        return isPositive ? -1 : 1;
    }
    // If the signs are the same, compare the absolute values of the numbers.
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size() ? -1 : 1;
    }
    for (int i = int(digits.size() - 1); i >= 0; --i) {
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
