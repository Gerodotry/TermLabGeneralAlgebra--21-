//
// Created by Dklishch on 5/8/2023.
//

#include "GUI/algorithms/PollardAlgorithm.h"
#include "utils/Int.h"
#include "algorithms/NaiveFactorization.h"
#include "GUI/inputComponents/NumberInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "algorithms/Pollard.h"


std::string PollardAlgorithm::getName() const {
    return "Pollard number factorization";
}

Object *PollardAlgorithm::run() {
    Number *numberA = dynamic_cast<Number *>(dataTypes[0]->getObject());
    result = Pollard::run(*numberA);
    return &result;
}

PollardAlgorithm::PollardAlgorithm() {
    dataTypes = {
        std::make_shared<NumberInputComponent>("Number")
    };
}