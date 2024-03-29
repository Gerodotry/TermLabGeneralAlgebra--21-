//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/algorithms/RingPolynomialMultiplicationAlgorithm.h"
#include "utils/Int.h"
#include "algorithms/PolynomialMultiplication.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "GUI/inputComponents/RingPolynomialInputComponent.h"
#include "GUI/inputComponents/NumberInputComponent.h"

std::string RingPolynomialMultiplicationAlgorithm::getName() const {
    return "Ring polynomial multiplication";
}

Object *RingPolynomialMultiplicationAlgorithm::run() {
    RingPolynomial *polynomialA = dynamic_cast<RingPolynomial *>(dataTypes[0]->getObject());
    RingPolynomial *polynomialB = dynamic_cast<RingPolynomial *>(dataTypes[1]->getObject());
    Number *module = dynamic_cast<Number *>(dataTypes[2]->getObject());
    result = PolynomialMultiplication::run(*polynomialA, *polynomialB, *module);
    return &result;
}

RingPolynomialMultiplicationAlgorithm::RingPolynomialMultiplicationAlgorithm() {
    dataTypes = {
            std::make_shared<RingPolynomialInputComponent>("PolynomialA"),
            std::make_shared<RingPolynomialInputComponent>("PolynomialB"),
            std::make_shared<NumberInputComponent>("Module")
    };
}