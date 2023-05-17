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
    int module = dynamic_cast<Int *>(dataTypes[1]->getObject())->get();
    result = NumberSqrt::run(*numberA, module);
    return &result;
}

NumberSqrtAlgorithm::NumberSqrtAlgorithm() {
    dataTypes = {
            std::make_shared<NumberInputComponent>("Number"),
            std::make_shared<IntInputComponent>("Module")
    };
}