//
// Created by Dklishch on 5/16/2023.
//

#ifndef LAB_POLYNOMIALGENERATORCHECKALGORITHM_H
#define LAB_POLYNOMIALGENERATORCHECKALGORITHM_H


#include "Algorithm.h"
#include "utils/Bool.h"
#include "utils/IsGenerator.h"

class PolynomialGeneratorCheckAlgorithm: public Algorithm {
public:
    PolynomialGeneratorCheckAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    IsGenerator result;
};

#endif //LAB_POLYNOMIALGENERATORCHECKALGORITHM_H
