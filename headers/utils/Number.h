#ifndef LAB_NUMBER_H
#define LAB_NUMBER_H

#include <algorithm>
#include <string>
#include <vector>

class Number {
    friend class NumberAddition;
    friend class NumberMultiplication;
    friend class NumberSubtraction;
public:
    Number() = default;

    explicit Number(const std::string& string) {
        if (string[0] == '-') {
            string.substr(1);
        } else {
            digitalize(string);
        }
        simplify();
    }

    explicit Number(int num) {
        if (num < 0) {
            sign = false;
            num = abs(num);
        }
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    unsigned int& operator [] (int i) {
        return digits[i];
    }

    unsigned int& operator [] (unsigned int i) {
        return digits[i];
    }

    unsigned int& operator [] (std::size_t i) {
        return digits[i];
    }

    bool operator == ( const Number& other) const {
        return digits == other.digits;
    }

    bool operator != (const Number& other) const {
        return !(*this == other);
    }

    bool operator > (const Number& other) const {
        return compareDigits(other) > 0;
    }

    bool operator >= (const Number& other) const {
        return compareDigits(other) >= 0;
    }

    bool operator < (const Number& other) const {
        return compareDigits(other) < 0;
    }

    bool operator <= (const Number& other) const {
        return compareDigits(other) <= 0;
    }

    bool isZero() const {
        return digits.empty();
    }

    std::string toString() const {
        if (isZero()) {
            return "0";
        }
        std::string str(digits.size(), '0');
        std::transform(digits.rbegin(), digits.rend(), str.begin(),
                       [](unsigned int d) { return d + '0'; });
        return (sign) ? str : ("-" + str);
    }

protected:
    bool sign = true;
    std::vector<unsigned int> digits;

    void simplify() {
        while (!digits.empty() && digits.back() == 0) {
            digits.pop_back();
        }
    }

    int compareDigits(const Number& other) const {
        if (sign != other.sign) {
            // If the signs are different, return -1 if this number is negative,
            // and return 1 if this number is positive.
            return sign ? -1 : 1;
        }
        // If the signs are the same, compare the absolute values of the numbers.
        if (digits.size() != other.digits.size()) {
            return digits.size() < other.digits.size() ? -1 : 1;
        }
        for (int i = int(digits.size() - 1); i >= 0; --i) {
            if (digits[i] < other.digits[i]) {
                return sign ? 1 : -1;
            }
            if (digits[i] > other.digits[i]) {
                return sign ? -1 : 1;
            }
        }
        return 0;
    }

    void digitalize(const std::string& str) {
        digits = std::vector<unsigned int>(str.size());
        for (size_t i = 0; i < str.size(); ++i) {
            digits[i] = str[str.size() - 1 - i] - '0';
        }
    }
};

#endif //LAB_NUMBER_H
