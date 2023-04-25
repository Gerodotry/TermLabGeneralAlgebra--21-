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

    explicit Number(const std::string& str) : digits(digitalize(str)) {
        simplify();
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

    bool operator ==( const Number& other) const {
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
        return str;
    }

private:
    std::vector<unsigned int> digits;

    void simplify() {
        while (!digits.empty() && digits.back() == 0) {
            digits.pop_back();
        }
    }

    int compareDigits(const Number& other) const {
        if (digits.size() != other.digits.size()) {
            return digits.size() < other.digits.size() ? -1 : 1;
        }
        for (int i = int(digits.size() - 1); i >= 0; --i) {
            if (digits[i] < other.digits[i]) {
                return -1;
            }
            if (digits[i] > other.digits[i]) {
                return 1;
            }
        }
        return 0;
    }

    static std::vector<unsigned int> digitalize(const std::string& str) {
        std::vector<unsigned int> digits;
        digits.reserve(str.size());
        for (auto it = str.rbegin(); it != str.rend(); ++it) {
            digits.emplace_back(*it - '0');
        }
        return digits;
    }
};

#endif //LAB_NUMBER_H
