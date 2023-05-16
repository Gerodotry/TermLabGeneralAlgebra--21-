//
// Created by Dklishch on 5/9/2023.
//

#include "GUI/algorithms/NumberSqrtAlgorithm.h"
#include "utils/Int.h"
#include "algorithms/NumberSqrt.h"
#include "GUI/inputComponents/NumberInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"


std::string NumberSqrtAlgorithm::getName() const {
    return "Number sqrt";
}

Object *NumberSqrtAlgorithm::run() {
    Number *numberA = dynamic_cast<Number *>(dataTypes[0]->getObject());
    Number *module = dynamic_cast<Number *>(dataTypes[1]->getObject());
    result = NumberSqrt::run(*numberA, *module);
    return &result;
}

NumberSqrtAlgorithm::NumberSqrtAlgorithm() {
    dataTypes = {
            std::make_shared<NumberInputComponent>("Number"),
            std::make_shared<NumberInputComponent>("Module")
    };
}