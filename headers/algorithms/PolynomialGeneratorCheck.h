#ifndef POLYNOMIAL_GENERATOR_CHECK_H
#define POLYNOMIAL_GENERATOR_CHECK_H

#include <vector>

class PolynomialGeneratorCheck {
public:
    static int find_order(const std::vector<int>& degrees);

    static int run(const std::vector<int>& poly, int field_size);

    static bool is_generator(const std::vector<int>& poly, int field_size, int& order);
private:
    static std::vector<int> multiply_polynomials(const std::vector<int>& a, const std::vector<int>& b, int field_size);
};
#endif