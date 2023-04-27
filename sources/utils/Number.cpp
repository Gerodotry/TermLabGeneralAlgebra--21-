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
        this->digits.push_back(num % 10);
        num /= 10;
    }
    simplify();
}

Number::Number(int num) {
    if (num < 0) {
        this->isPositive = false;
        num = abs(num);
    }
    while (num > 0) {
        this->digits.push_back(num % 10);
        num /= 10;
    }
    simplify();
}

unsigned int &Number::operator[](int i) {
    return this->digits[i];
}

unsigned int &Number::operator[](unsigned int i) {
    return this->digits[i];
}

unsigned int &Number::operator[](std::size_t i) {
    return this->digits[i];
}

bool Number::operator==(const Number &other) const {
    return this->digits == other.digits;
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
    return this->digits.empty();
}

std::string Number::toString(bool abs) const {
    if (isZero()) {
        return "0";
    }
    std::string str(this->digits.size(), '0');
    std::transform(this->digits.rbegin(), this->digits.rend(), str.begin(),
                   [](unsigned int d) { return d + '0'; });
    return (this->isPositive || abs) ? str : ("-" + str);
}

void Number::simplify() {
    if (isZero()) {
        this->isPositive = true;
    }
    while (!this->digits.empty() && this->digits.back() == 0) {
        this->digits.pop_back();
    }
}

void Number::toField(unsigned int modulo) {
    // Compute the value of the number in the given field
    unsigned int value = 0;
    for (int i = int(this->digits.size() - 1); i >= 0; --i) {
        value = (value * 10 + this->digits[i]) % modulo;
    }
    if (!this->isPositive) {
        value = modulo - value;
        this->isPositive = true;
    }
    // Convert the value back to digits
    this->digits.clear();
    int nDigits = int(floor(log10(value)) + 1);
    for (int i = 0; i < nDigits; ++i) {
        this->digits.push_back(value % 10);
        value /= 10;
    }
}

int Number::compareDigits(const Number &other) const {
    if (this->isPositive != other.isPositive) {
        // If the signs are different, return -1 if this number is negative,
        // and return 1 if this number is positive.
        return this->isPositive ? -1 : 1;
    }
    // If the signs are the same, compare the absolute values of the numbers.
    if (this->digits.size() != other.digits.size()) {
        return this->digits.size() < other.digits.size() ? -1 : 1;
    }
    for (int i = int(this->digits.size() - 1); i >= 0; --i) {
        if (this->digits[i] < other.digits[i]) {
            return this->isPositive ? 1 : -1;
        }
        if (this->digits[i] > other.digits[i]) {
            return this->isPositive ? -1 : 1;
        }
    }
    return 0;
}

void Number::digitalize(const std::string &str) {
    this->digits = std::vector<unsigned int>(str.size());
    for (size_t i = 0; i < str.size(); ++i) {
        this->digits[i] = str[str.size() - 1 - i] - '0';
    }
    simplify();
}
