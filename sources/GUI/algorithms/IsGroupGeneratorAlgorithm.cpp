//
// Created by Dklishch on 6/1/2023.
//

#include "GUI/algorithms/IsGroupGeneratorAlgorithm.h"
#include "GUI/inputComponents/NumberInputComponent.h"
#include "GUI/inputComponents/NumberSetInputComponent.h"
#include "algorithms/IsGroupGenerator.h"

std::string IsGroupGeneratorAlgorithm::getName() const {
    return "Is group generator";
}

Object *IsGroupGeneratorAlgorithm::run() {
    Number *number = dynamic_cast<Number *>(dataTypes[0]->getObject());
    NumberSet *fieldGroup = dynamic_cast<NumberSet *>(dataTypes[1]->getObject());
    Number *module = dynamic_cast<Number *>(dataTypes[2]->getObject());
    result = IsGroupGenerator::run(*number, fieldGroup->numbers, *module);
    return &result;
}

IsGroupGeneratorAlgorithm::IsGroupGeneratorAlgorithm() {
    dataTypes = {
            std::make_shared<NumberInputComponent>("Number"),
            std::make_shared<NumberSetInputComponent>("Field group"),
            std::make_shared<NumberInputComponent>("Module")
    };
}