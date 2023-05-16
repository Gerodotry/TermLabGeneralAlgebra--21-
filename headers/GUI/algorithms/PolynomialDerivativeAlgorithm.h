//
// Created by Dklishch on 5/15/2023.
//

#ifndef LAB_POLYNOMIALDERIVATIVEALGORITHM_H
#define LAB_POLYNOMIALDERIVATIVEALGORITHM_H


#include "Algorithm.h"
#include "utils/RingPolynomial.h"

class PolynomialDerivativeAlgorithm : public Algorithm {
public:
    PolynomialDerivativeAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    RingPolynomial result;
};

#endif //LAB_POLYNOMIALDERIVATIVEALGORITHM_H
