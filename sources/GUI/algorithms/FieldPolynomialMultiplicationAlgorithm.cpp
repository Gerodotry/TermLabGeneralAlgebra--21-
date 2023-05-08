//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/algorithms/FieldPolynomialMultiplicationAlgorithm.h"
#include "utils/Int.h"
#include "algorithms/PolynomialMultiplication.h"
#include "GUI/inputComponents/FieldPolynomialInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"

std::string FieldPolynomialMultiplicationAlgorithm::getName() const {
    return "Field polynomial multiplication";
}

Object *FieldPolynomialMultiplicationAlgorithm::run() {
    FieldPolynomial *polynomialA = dynamic_cast<FieldPolynomial *>(dataTypes[0]->getObject());
    FieldPolynomial *polynomialB = dynamic_cast<FieldPolynomial *>(dataTypes[1]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[2]->getObject())->get();
    result = PolynomialMultiplication::run(*polynomialA, *polynomialB, module);
    return &result;
}

FieldPolynomialMultiplicationAlgorithm::FieldPolynomialMultiplicationAlgorithm() {
    dataTypes = {
            std::make_shared<FieldPolynomialInputComponent>("PolynomialA"),
            std::make_shared<FieldPolynomialInputComponent>("PolynomialB"),
            std::make_shared<IntInputComponent>("Module")
    };
}