#ifndef LAB_BIGINTEGER_H
#define LAB_BIGINTEGER_H
#pragma once

#include <string>
#include <iomanip>
#include <random>
#include <chrono>
#include <complex>
#include "Object.h"

class BigInt: public Object {
public:
    static constexpr int maxn = 1e2 + 14, lg = 15;
    static constexpr int base = 1000000000;
    static constexpr int base_digits = 9;

    std::vector<int> a;
    int sign;

    int size();

    BigInt operator^(const BigInt &v);

    std::string to_string();

    int sumof();

    /*</arpa>*/
    BigInt();

    BigInt(long long v);

    BigInt(const std::string &s);

    void operator=(const BigInt &v);

    void operator=(long long v);

    BigInt operator+(const BigInt &v) const;

    BigInt operator-(const BigInt &v) const;

    void operator*=(int v);

    BigInt operator*(int v) const;

    void operator*=(long long v);

    BigInt operator*(long long v) const;

    friend std::pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1);

    BigInt operator/(const BigInt &v) const;

    BigInt operator%(const BigInt &v) const;

    void operator/=(int v);

    BigInt operator/(int v) const;

    int operator%(int v) const;

    void operator+=(const BigInt &v);

    void operator-=(const BigInt &v);

    void operator*=(const BigInt &v);

    void operator/=(const BigInt &v);

    bool operator<(const BigInt &v) const;

    bool operator>(const BigInt &v) const;

    bool operator<=(const BigInt &v) const;

    bool operator>=(const BigInt &v) const;

    bool operator==(const BigInt &v) const;

    bool operator!=(const BigInt &v) const;

    void trim();

    bool isZero() const;

    BigInt operator-() const;

    BigInt abs() const;

    long long longValue() const;

    friend BigInt gcd(const BigInt &a, const BigInt &b);

    friend BigInt lcm(const BigInt &a, const BigInt &b);

    void read(const std::string &s);

    friend std::istream &operator>>(std::istream &stream, BigInt &v);

    friend std::ostream &operator<<(std::ostream &stream, const BigInt &v);

    static std::vector<int> convert_base(const std::vector<int> &a, int old_digits, int new_digits);

    static std::vector<long long>  karatsubaMultiply(const std::vector<long long>  &a, const std::vector<long long>  &b);

    BigInt operator*(const BigInt &v) const;
};

#endif //LAB_BIGINTEGER_H