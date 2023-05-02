//
// Created by Dklishch on 4/24/2023.
//

#ifndef MAIN_CPP_NumberDivisionAlgorithm_H
#define MAIN_CPP_NumberDivisionAlgorithm_H

#include "Algorithm.h"
#include "utils/Number.h"

class NumberDivisionAlgorithm : public Algorithm {
public:
    NumberDivisionAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    Number result;
};


#endif //MAIN_CPP_NumberDivisionAlgorithm_H
