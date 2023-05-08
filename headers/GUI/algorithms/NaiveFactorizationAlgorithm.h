//
// Created by Dklishch on 5/8/2023.
//

#ifndef LAB_NAIVEFACTORIZATIONALGORITHM_H
#define LAB_NAIVEFACTORIZATIONALGORITHM_H


#include "utils/Number.h"
#include "Algorithm.h"
#include "utils/NumberFactors.h"

class NaiveFactorizationAlgorithm : public Algorithm {
public:
    NaiveFactorizationAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    NumberFactors result;
};

#endif //LAB_NAIVEFACTORIZATIONALGORITHM_H
