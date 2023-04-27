#include "../../headers/utils/Number.h"

Number::Number(const std::string &string) {
    if (string[0] == '-') {
        isPositive = false;
        digitalize(string.substr(1));
    } else {
        digitalize(string);
    }
    simplify();
}

Number::Number(unsigned int num) {
    while (num > 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
    simplify();
}

Number::Number(int num) {
    if (num < 0) {
        isPositive = false;
        num = abs(num);
    }
    while (num > 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
    simplify();
}

unsigned int &Number::operator[](int i) {
    return digits[i];
}

unsigned int &Number::operator[](unsigned int i) {
    return digits[i];
}

unsigned int &Number::operator[](std::size_t i) {
    return digits[i];
}

bool Number::operator==(const Number &other) const {
    return digits == other.digits;
}

bool Number::operator>(const Number &other) const {
    return compareDigits(other) > 0;
}

bool Number::operator!=(const Number &other) const {
    return !(*this == other);
}

bool Number::operator>=(const Number &other) const {
    return compareDigits(other) >= 0;
}

bool Number::operator<(const Number &other) const {
    return compareDigits(other) < 0;
}

bool Number::operator<=(const Number &other) const {
    return compareDigits(other) <= 0;
}

bool Number::isZero() const {
    return digits.empty();
}

std::string Number::toString(bool abs = false) const {
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
    if (!isPositive) {
        value = modulo - value;
        isPositive = true;
    }
    // Convert the value back to digits
    digits.clear();
    int nDigits = ceil(log10(value));
    for(int i = 0; i < nDigits; ++i) {
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
            return isPositive ? 1 : -1;
        }
        if (digits[i] > other.digits[i]) {
            return isPositive ? -1 : 1;
        }
    }
    return 0;
}

void Number::digitalize(const std::string &str) {
    digits = std::vector<unsigned int>(str.size());
    for (size_t i = 0; i < str.size(); ++i) {
        digits[i] = str[str.size() - 1 - i] - '0';
    }
    simplify();
}
