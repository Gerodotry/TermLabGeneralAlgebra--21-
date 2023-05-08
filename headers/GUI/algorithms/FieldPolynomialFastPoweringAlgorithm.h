//
// Created by Dklishch on 4/24/2023.
//

#ifndef MAIN_CPP_FieldPolynomialFastPoweringAlgorithm_H
#define MAIN_CPP_FieldPolynomialFastPoweringAlgorithm_H

#include "Algorithm.h"
#include "utils/Number.h"
#include "utils/FieldPolynomial.h"

class FieldPolynomialFastPoweringAlgorithm : public Algorithm {
public:
    FieldPolynomialFastPoweringAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    FieldPolynomial result;
};


#endif //MAIN_CPP_FieldPolynomialFastPoweringAlgorithm_H
