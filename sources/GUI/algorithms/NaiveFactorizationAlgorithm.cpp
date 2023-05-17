//
// Created by Dklishch on 5/8/2023.
//

#include "GUI/algorithms/NaiveFactorizationAlgorithm.h"
#include "utils/Int.h"
#include "algorithms/NaiveFactorization.h"
#include "GUI/inputComponents/NumberInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"

std::string NaiveFactorizationAlgorithm::getName() const {
    return "Naive number factorization";
}

Object *NaiveFactorizationAlgorithm::run() {
    Number *numberA = dynamic_cast<Number *>(dataTypes[0]->getObject());
    result = NaiveFactorization::run(*numberA);
    return &result;
}

NaiveFactorizationAlgorithm::NaiveFactorizationAlgorithm() {
    dataTypes = {
            std::make_shared<NumberInputComponent>("Number"),
            std::make_shared<IntInputComponent>("Module")
    };
}