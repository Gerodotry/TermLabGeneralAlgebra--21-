//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/NumberSubtractionAlgorithm.h"
#include "GUI/InputComponents/NumberInputComponent.h"
#include "algorithms/NumberSubtraction.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"

std::string NumberSubtractionAlgorithm::getName() const {
    return "Number subtraction";
}

Object *NumberSubtractionAlgorithm::run() {
    Number *numberA = dynamic_cast<Number *>(dataTypes[0]->getObject());
    Number *numberB = dynamic_cast<Number *>(dataTypes[1]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[2]->getObject())->get();
    result = NumberSubtraction::run(*numberA, *numberB, module);
    return &result;
}

NumberSubtractionAlgorithm::NumberSubtractionAlgorithm() {
    dataTypes = {
            std::make_shared<NumberInputComponent>("NumberA"),
            std::make_shared<NumberInputComponent>("NumberB"),
            std::make_shared<IntInputComponent>("Module")
    };
}