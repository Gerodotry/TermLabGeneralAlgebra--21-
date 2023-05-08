//
// Created by Dklishch on 4/24/2023.
//

#ifndef MAIN_CPP_FieldPolynomialSubtractionAlgorithm_H
#define MAIN_CPP_FieldPolynomialSubtractionAlgorithm_H

#include "Algorithm.h"
#include "utils/Number.h"
#include "utils/FieldPolynomial.h"

class FieldPolynomialSubtractionAlgorithm : public Algorithm {
public:
    FieldPolynomialSubtractionAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    FieldPolynomial result;
};


#endif //MAIN_CPP_FieldPolynomialSubtractionAlgorithm_H
