#include "algorithms/PolynomialGeneratorCheck.h"
#include <vector>

int PolynomialGeneratorCheck::find_order(const std::vector<int>& degrees) {
    int order = 0;
    for (int degree : degrees) {
        if (degree > order) {
            order = degree;
        }
    }
    return order;
} 

bool PolynomialGeneratorCheck::is_generator(const std::vector<int>& degrees, int field_size) {
    int order = find_order(degrees);
    return order == field_size - 1;
}

int PolynomialGeneratorCheck::run(const std::vector<int>& degrees, int field_size) {
    std::vector<int> powers(field_size - 1, 0);
    int x = 1;
    int order = 0;

    while (true) {
        powers[x % (field_size - 1)] = 1;
        x = multiply_polynomials({ x }, degrees, field_size)[0];
        order++;

        if (powers[x % (field_size - 1)] == 1) {
            break;
        }
    }

    return order;
}

bool PolynomialGeneratorCheck::is_generator(const std::vector<int>& degrees, int field_size) {
    int order = find_order(degrees);
    return order == field_size - 1;
}

std::vector<int> PolynomialGeneratorCheck::multiply_polynomials(const std::vector<int>& a, const std::vector<int>& b, int field_size) {
    std::vector<int> result(a.size() + b.size() - 1, 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            result[i + j] = (result[i + j] + (a[i] * b[j]) % field_size) % field_size;
        }
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return result;
}