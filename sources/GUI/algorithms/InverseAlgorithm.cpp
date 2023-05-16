//
//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/InverseAlgorithm.h"
#include "GUI/InputComponents/NumberInputComponent.h"
#include "algorithms/Inverse.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"

std::string InverseAlgorithm::getName() const {
    return "Inverse number";
}

Object *InverseAlgorithm::run() {
    Number *numberA = dynamic_cast<Number *>(dataTypes[0]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[1]->getObject())->get();
    result = Inverse::run(*numberA, module);
    return &result;
}

InverseAlgorithm::InverseAlgorithm() {
    dataTypes = {
            std::make_shared<NumberInputComponent>("NumberA"),
            std::make_shared<IntInputComponent>("Module")
    };
}// Created by mac on 08.05.2023.
//
