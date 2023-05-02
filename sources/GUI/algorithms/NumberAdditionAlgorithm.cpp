//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/NumberAdditionAlgorithm.h"
#include "GUI/InputComponents/NumberInputComponent.h"
#include "algorithms/NumberAddition.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"

std::string NumberAdditionAlgorithm::getName() const {
    return "Number addition";
}

Object *NumberAdditionAlgorithm::run() {
    Number *numberA = dynamic_cast<Number *>(dataTypes[0]->getObject());
    Number *numberB = dynamic_cast<Number *>(dataTypes[1]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[2]->getObject())->get();
    result = NumberAddition::run(*numberA, *numberB, module);
    return &result;
}

NumberAdditionAlgorithm::NumberAdditionAlgorithm() {
    dataTypes = {
            std::make_shared<NumberInputComponent>("NumberA"),
            std::make_shared<NumberInputComponent>("NumberB"),
            std::make_shared<IntInputComponent>("Module")
    };
}