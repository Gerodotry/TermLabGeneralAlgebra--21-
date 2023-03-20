//
// Created by Ihor on 19.03.2023.
//

#ifndef LAB_NUMBER_H
#define LAB_NUMBER_H

#include <vector>
#include <string>

using std::vector;
using std::string;
using std:: isdigit;
using std:: size_t;
using std:: cout;
using std:: endl;

class Number {
private:
    vector<unsigned int> digits;

    bool isEqual(Number& n) const {
        if (digits.size() != n.digits.size())
            return false;
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] != n[i])
                return false;
        }
        return true;
    }

    static vector<unsigned int> digitalize(const string& str)
    {
        vector<unsigned int> digits;
        for (char c : str) {
            if (isdigit(c)) {
                digits.push_back(c - '0');
            }
        }
        return digits;
    }
public:
    Number() = default;

    explicit Number(const string& str) {
        this->digits = digitalize(str);
    }

    explicit Number(const vector<unsigned int>& digits) {
        this->digits = digits;
    }

    unsigned int &operator[](unsigned int i) {
        return digits[i];
    }

    unsigned int &operator[](int i) {
        return digits[i];
    }

    unsigned int &operator[](size_t i) {
        return digits[i];
    }

    bool operator == (const Number& other) const {
        if (digits.size() != other.digits.size()) {
            return false;
        }
        for (unsigned int i = 0; i < digits.size(); i++) {
            if (digits[i] != other.digits[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator != (Number& n) const {
        return !isEqual(n);
    }

    size_t getSize() {
        return this->digits.size();
    }

    Number simplify() {
        while (!digits.empty() && digits.back() == 0) {
            this->digits.pop_back();
        }
        return (*this);
    }

    string toString() {
        if (this->digits.empty()) {
            return "0";
        }
        string result;
        for (unsigned int i : this->digits) {
            do {
                result += static_cast<char>('0' + (i % 10));
                i /= 10;
            } while (i != 0);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    void print(bool printNewLine = false) {
        cout << this->toString();
        if (printNewLine) {
            cout << endl;
        }
    }
};
#endif //LAB_NUMBER_H