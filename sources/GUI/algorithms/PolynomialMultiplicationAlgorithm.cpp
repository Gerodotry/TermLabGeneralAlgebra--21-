//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/algorithms/PolynomialMultiplicationAlgorithm.h"
#include "utils/Int.h"
#include "algorithms/PolynomialMultiplication.h"
#include "GUI/inputComponents/PolynomialInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"

std::string PolynomialMultiplicationAlgorithm::getName() const {
    return "Polynomial multiplication";
}

Object *PolynomialMultiplicationAlgorithm::run() {
    Polynomial *polynomialA = dynamic_cast<Polynomial *>(dataTypes[0]->getObject());
    Polynomial *polynomialB = dynamic_cast<Polynomial *>(dataTypes[1]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[2]->getObject())->get();
    result = PolynomialMultiplication::run(*polynomialA, *polynomialB, module);
    return &result;
}

PolynomialMultiplicationAlgorithm::PolynomialMultiplicationAlgorithm() {
    dataTypes = {
            std::make_shared<PolynomialInputComponent>("PolynomialA"),
            std::make_shared<PolynomialInputComponent>("PolynomialB"),
            std::make_shared<IntInputComponent>("Module")
    };
}