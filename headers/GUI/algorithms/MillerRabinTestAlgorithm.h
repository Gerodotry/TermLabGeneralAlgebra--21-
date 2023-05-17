//
// Created by Dklishch on 5/8/2023.
//

#ifndef LAB_MILLERRABINTESTALGORITHM_H
#define LAB_MILLERRABINTESTALGORITHM_H

#include "Algorithm.h"
#include "utils/Bool.h"

class MillerRabinTestAlgorithm : public Algorithm {
public:
    MillerRabinTestAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    Bool result;
};

#endif //LAB_MILLERRABINTESTALGORITHM_H
