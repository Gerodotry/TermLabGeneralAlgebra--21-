//
// Created by Dklishch on 4/24/2023.
//

#ifndef MAIN_CPP_FieldPolynomialAdditionAlgorithm_H
#define MAIN_CPP_FieldPolynomialAdditionAlgorithm_H

#include "Algorithm.h"
#include "utils/Number.h"
#include "utils/RingPolynomial.h"
#include "utils/FieldPolynomial.h"

class FieldPolynomialAdditionAlgorithm : public Algorithm {
public:
    FieldPolynomialAdditionAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    FieldPolynomial result;
};


#endif //MAIN_CPP_FieldPolynomialAdditionAlgorithm_H
