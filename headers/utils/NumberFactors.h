//
// Created by Dklishch on 5/8/2023.
//

#ifndef LAB_NUMBERFACTORS_H
#define LAB_NUMBERFACTORS_H

#include "Object.h"
#include "Number.h"

class NumberFactors: public Object {
public:
    std::vector<Number> numbers;

    NumberFactors();

    NumberFactors(const std::vector<Number>& numbers);

    std::string toString() override;
};


#endif //LAB_NUMBERFACTORS_H
