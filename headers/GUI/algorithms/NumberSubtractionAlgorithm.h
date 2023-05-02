//
// Created by Dklishch on 4/24/2023.
//

#ifndef MAIN_CPP_NumberSubtractionAlgorithm_H
#define MAIN_CPP_NumberSubtractionAlgorithm_H

#include "Algorithm.h"
#include "utils/Number.h"

class NumberSubtractionAlgorithm : public Algorithm {
public:
    NumberSubtractionAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    Number result;
};


#endif //MAIN_CPP_NumberSubtractionAlgorithm_H
