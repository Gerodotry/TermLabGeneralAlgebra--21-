//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/NumberGCDAlgorithm.h"
#include "GUI/InputComponents/NumberInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"
#include "algorithms/NumberGCD.h"

std::string NumberGCDAlgorithm::getName() const {
    return "Number GCD";
}

Object *NumberGCDAlgorithm::run() {
    Number *numberA = dynamic_cast<Number *>(dataTypes[0]->getObject());
    Number *numberB = dynamic_cast<Number *>(dataTypes[1]->getObject());
    Number *module = dynamic_cast<Number *>(dataTypes[2]->getObject());
    result = NumberGCD::run(*numberA, *numberB, *module);
    return &result;
}

NumberGCDAlgorithm::NumberGCDAlgorithm() {
    dataTypes = {
            std::make_shared<NumberInputComponent>("NumberA"),
            std::make_shared<NumberInputComponent>("NumberB"),
            std::make_shared<NumberInputComponent>("Module")
    };
}