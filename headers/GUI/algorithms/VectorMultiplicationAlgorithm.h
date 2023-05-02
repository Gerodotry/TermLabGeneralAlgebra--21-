//
// Created by Dklishch on 4/24/2023.
//

#ifndef MAIN_CPP_VECTORMULTIPLICATIONALGORITHM_H
#define MAIN_CPP_VECTORMULTIPLICATIONALGORITHM_H

#include "Algorithm.h"
#include "utils/Float.h"

class VectorMultiplicationAlgorithm : public Algorithm {
public:
    VectorMultiplicationAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;

    virtual const std::vector<std::shared_ptr<InputComponent>>& getTypes() const override;
private:
    Float result;
};


#endif //MAIN_CPP_VECTORMULTIPLICATIONALGORITHM_H
