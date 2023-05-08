//
// Created by Dklishch on 4/24/2023.
//

#ifndef MAIN_CPP_RingPolynomialMultiplicationAlgorithm_H
#define MAIN_CPP_RingPolynomialMultiplicationAlgorithm_H

#include "Algorithm.h"
#include "utils/Number.h"
#include "utils/RingPolynomial.h"

class RingPolynomialMultiplicationAlgorithm : public Algorithm {
public:
    RingPolynomialMultiplicationAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    RingPolynomial result;
};


#endif //MAIN_CPP_RingPolynomialMultiplicationAlgorithm_H
