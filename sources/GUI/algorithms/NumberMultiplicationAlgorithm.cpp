//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/NumberMultiplicationAlgorithm.h"
#include "GUI/InputComponents/NumberInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"
#include "algorithms/NumberMultiplication.h"

std::string NumberMultiplicationAlgorithm::getName() const {
    return "Number multiplication";
}

Object *NumberMultiplicationAlgorithm::run() {
    Number *numberA = dynamic_cast<Number *>(dataTypes[0]->getObject());
    Number *numberB = dynamic_cast<Number *>(dataTypes[1]->getObject());
    Number *module = dynamic_cast<Number *>(dataTypes[2]->getObject());
    result = NumberMultiplication::run(*numberA, *numberB, *module);
    return &result;
}

NumberMultiplicationAlgorithm::NumberMultiplicationAlgorithm() {
    dataTypes = {
            std::make_shared<NumberInputComponent>("NumberA"),
            std::make_shared<NumberInputComponent>("NumberB"),
            std::make_shared<NumberInputComponent>("Module")
    };
}