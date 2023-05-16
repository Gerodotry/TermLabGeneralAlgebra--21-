//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/NumberDivisionAlgorithm.h"
#include "GUI/InputComponents/NumberInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"
#include "algorithms/NumberDivision.h"

std::string NumberDivisionAlgorithm::getName() const {
    return "Number division";
}

Object *NumberDivisionAlgorithm::run() {
    Number *numberA = dynamic_cast<Number *>(dataTypes[0]->getObject());
    Number *numberB = dynamic_cast<Number *>(dataTypes[1]->getObject());
    Number *module = dynamic_cast<Number *>(dataTypes[2]->getObject());
    result = NumberDivision::run(*numberA, *numberB, *module);
    return &result;
}

NumberDivisionAlgorithm::NumberDivisionAlgorithm() {
    dataTypes = {
            std::make_shared<NumberInputComponent>("NumberA"),
            std::make_shared<NumberInputComponent>("NumberB"),
            std::make_shared<NumberInputComponent>("Module")
    };
}