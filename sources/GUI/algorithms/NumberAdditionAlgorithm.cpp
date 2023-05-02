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

std::vector<InputComponent*> NumberAdditionAlgorithm::getTypes() const {
    return dataTypes;
}

Object* NumberAdditionAlgorithm::run() {
    Number* numberA = dynamic_cast<Number*>(dataTypes[0]->getObject());
    Number* numberB = dynamic_cast<Number*>(dataTypes[1]->getObject());
    int module = dynamic_cast<Int*>(dataTypes[2]->getObject())->get();
    return new Number(NumberAddition::run(*numberA, *numberB, module));
}

NumberAdditionAlgorithm::NumberAdditionAlgorithm() {
    dataTypes = {new NumberInputComponent("NumberA"), new NumberInputComponent("NumberB"), new IntInputComponent("Module")};
}

NumberAdditionAlgorithm::~NumberAdditionAlgorithm() {
    for (auto type: dataTypes) {
        delete type;
    }
    dataTypes.clear();
}