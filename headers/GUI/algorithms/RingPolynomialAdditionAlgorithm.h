//
// Created by Dklishch on 4/24/2023.
//

#ifndef MAIN_CPP_PolynomialAdditionAlgorithm_H
#define MAIN_CPP_PolynomialAdditionAlgorithm_H

#include "Algorithm.h"
#include "utils/Number.h"
#include "utils/RingPolynomial.h"

class PolynomialAdditionAlgorithm : public Algorithm {
public:
    PolynomialAdditionAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    RingPolynomial result;
};


#endif //MAIN_CPP_PolynomialAdditionAlgorithm_H
