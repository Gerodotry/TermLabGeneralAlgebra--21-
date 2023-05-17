//
// Created by Dklishch on 5/9/2023.
//

#ifndef LAB_NUMBERSQRTALGORITHM_H
#define LAB_NUMBERSQRTALGORITHM_H


#include "Algorithm.h"
#include "utils/Number.h"

class NumberSqrtAlgorithm : public Algorithm {
public:
    NumberSqrtAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    Number result;
};

#endif //LAB_NUMBERSQRTALGORITHM_H
