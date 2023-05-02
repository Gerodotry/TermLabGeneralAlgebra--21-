//
// Created by Dklishch on 4/24/2023.
//

#ifndef MAIN_CPP_NUMBERADDITIONALGORITHM_H
#define MAIN_CPP_NUMBERADDITIONALGORITHM_H

#include "Algorithm.h"
#include "utils/Number.h"

class NumberAdditionAlgorithm : public Algorithm {
public:
    NumberAdditionAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    Number result;
};


#endif //MAIN_CPP_VECTORMULTIPLICATIONALGORITHM_H
