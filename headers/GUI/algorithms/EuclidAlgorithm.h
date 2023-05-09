//
// Created by Dklishch on 5/9/2023.
//

#ifndef LAB_EUCLIDALGORITHM_H
#define LAB_EUCLIDALGORITHM_H

#include "Algorithm.h"
#include "utils/EuclidResult.h"

class EuclidAlgorithm : public Algorithm {
public:
    EuclidAlgorithm();

    std::string getName() const override;

    virtual Object *run() override;
private:
    EuclidResult result;
};

#endif //LAB_EUCLIDALGORITHM_H
