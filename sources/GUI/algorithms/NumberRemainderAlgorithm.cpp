//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/NumberRemainderAlgorithm.h"
#include "GUI/InputComponents/NumberInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"
#include "algorithms/NumberRemainder.h"

std::string NumberRemainderAlgorithm::getName() const {
    return "Number remainder";
}

Object *NumberRemainderAlgorithm::run() {
    Number *numberA = dynamic_cast<Number *>(dataTypes[0]->getObject());
    Number *numberB = dynamic_cast<Number *>(dataTypes[1]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[2]->getObject())->get();
    result = NumberRemainder::run(*numberA, *numberB, module);
    return &result;
}

NumberRemainderAlgorithm::NumberRemainderAlgorithm() {
    dataTypes = {
            std::make_shared<NumberInputComponent>("NumberA"),
            std::make_shared<NumberInputComponent>("NumberB"),
            std::make_shared<IntInputComponent>("Module")
    };
}