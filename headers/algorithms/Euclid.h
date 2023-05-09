#ifndef LAB_EUCLID_H
#define LAB_EUCLID_H
#include <vector>
#include "utils/FieldPolynomial.h"

class Euclid {
public:
    static std::vector<FieldPolynomial> run(FieldPolynomial r1, FieldPolynomial r2, unsigned int modulo);

private:
    static std::vector<FieldPolynomial> euclid_inversion(FieldPolynomial &r1, FieldPolynomial &r2, unsigned int modulo);

    static void euclid(FieldPolynomial r1, FieldPolynomial r2, FieldPolynomial &gcd, FieldPolynomial &a, FieldPolynomial &b, unsigned int modulo);

    static void inversion(FieldPolynomial r1, FieldPolynomial r2, FieldPolynomial x1, FieldPolynomial x2, FieldPolynomial y1, FieldPolynomial y2, FieldPolynomial &gcd, FieldPolynomial &a, FieldPolynomial &b, unsigned int modulo);
};

#endif //LAB_EUCLID_H
