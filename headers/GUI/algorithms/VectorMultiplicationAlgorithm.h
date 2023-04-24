//
// Created by Dklishch on 4/24/2023.
//

#ifndef MAIN_CPP_VECTORMULTIPLICATIONALGORITHM_H
#define MAIN_CPP_VECTORMULTIPLICATIONALGORITHM_H

#include "Algorithm.h"

class VectorMultiplicationAlgorithm : public Algorithm {
public:
    VectorMultiplicationAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;

    virtual std::vector<InputComponent*> getTypes() const override;

    ~VectorMultiplicationAlgorithm();
private:
    std::vector<InputComponent *> dataTypes;
};


#endif //MAIN_CPP_VECTORMULTIPLICATIONALGORITHM_H
