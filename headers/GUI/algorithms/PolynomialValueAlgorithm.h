//
// Created by Dklishch on 5/15/2023.
//

#ifndef LAB_POLYNOMIALVALUEALGORITHM_H
#define LAB_POLYNOMIALVALUEALGORITHM_H


#include "Algorithm.h"
#include "utils/Number.h"

class PolynomialValueAlgorithm: public Algorithm {
public:
    PolynomialValueAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    Number result;
};

#endif //LAB_POLYNOMIALVALUEALGORITHM_H
