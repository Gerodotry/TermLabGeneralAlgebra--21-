#include "algorithms/PolynomialGenerateorCheck.h"
#include <vector>

PolynomialGeneratorCheck::is_generator(const std::vector<int>& poly, int field_size) {
    std::vector<int> powers(field_size - 1, 0);
    int x = 1;
    for (int i = 0; i < field_size - 2; i++) {
        powers[x] = i + 1;
        x = multiply_polynomials(x, poly, field_size);
    }

    for (int i = 1; i < field_size; i++) {
        if (powers[i] == 0) {
            return false;
        }
    }
    return true;
}


PolynomialGeneratorCheck::run(const std::vector<int>& poly, int field_size) {
    std::vector<int> powers(field_size - 1, 0);
    int x = 1;
    for (int i = 0; i < field_size - 2; i++) {
        powers[x] = i + 1;
        x = multiply_polynomials(x, poly, field_size);
    }

    for (int i = 1; i < field_size; i++) {
        if (powers[i] == 0) {
            return i;
        }
    }
    return field_size - 1;
}

PolynomialGeneratorCheck::multiply_polynomials(const std::vector<int>& a, const std::vector<int>& b, int field_size) {
    std::vector<int> result(a.size() + b.size() - 1, 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            result[i + j] = (result[i + j] + a[i] * b[j]) % field_size;
        }
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return result;
}
};