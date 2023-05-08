#ifndef POLYNOMIAL_GENERATOR_CHECK_H
#define POLYNOMIAL_GENERATOR_CHECK_H

#include <vector>

class PolynomialGeneratorCheck {
public:

    static bool is_generator(const std::vector<int>& poly, int field_size);

    static int run(const std::vector<int>& poly, int field_size);

private:

    static std::vector<int> multiply_polynomials(const std::vector<int>& a, const std::vector<int>& b, int field_size);
};
#endif