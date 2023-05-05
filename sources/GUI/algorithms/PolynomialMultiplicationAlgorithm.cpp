//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/algorithms/PolynomialMultiplicationAlgorithm.h"
#include "utils/Int.h"
#include "algorithms/RingPolynomialMultiplication.h"
#include "GUI/inputComponents/PolynomialInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"

std::string PolynomialMultiplicationAlgorithm::getName() const {
    return "RingPolynomial multiplication";
}

Object *PolynomialMultiplicationAlgorithm::run() {
    RingPolynomial *polynomialA = dynamic_cast<RingPolynomial *>(dataTypes[0]->getObject());
    RingPolynomial *polynomialB = dynamic_cast<RingPolynomial *>(dataTypes[1]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[2]->getObject())->get();
    result = RingPolynomialMultiplication::run(*polynomialA, *polynomialB, module);
    return &result;
}

PolynomialMultiplicationAlgorithm::PolynomialMultiplicationAlgorithm() {
    dataTypes = {
            std::make_shared<PolynomialInputComponent>("PolynomialA"),
            std::make_shared<PolynomialInputComponent>("PolynomialB"),
            std::make_shared<IntInputComponent>("Module")
    };
}