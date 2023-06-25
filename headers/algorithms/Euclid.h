
#ifndef LAB_EUCLID_H
#define LAB_EUCLID_H
#include <vector>
#include "utils/FieldPolynomial.h"

class Euclid {
public:
    static FieldPolynomial run(FieldPolynomial r1, FieldPolynomial r2);

private:

    static FieldPolynomial extendedEuclideanAlgorithm(const FieldPolynomial &a, const FieldPolynomial &b);
};

#endif //LAB_EUCLID_H