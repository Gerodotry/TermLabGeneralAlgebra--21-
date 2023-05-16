//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/FieldPolynomialSubtractionAlgorithm.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"
#include "GUI/inputComponents/FieldPolynomialInputComponent.h"
#include "algorithms/PolynomialSubtraction.h"
#include "GUI/inputComponents/NumberInputComponent.h"

std::string FieldPolynomialSubtractionAlgorithm::getName() const {
    return "Field polynomial subtraction";
}

Object *FieldPolynomialSubtractionAlgorithm::run() {
    FieldPolynomial *polynomialA = dynamic_cast<FieldPolynomial *>(dataTypes[0]->getObject());
    FieldPolynomial *polynomialB = dynamic_cast<FieldPolynomial *>(dataTypes[1]->getObject());
    Number* module = dynamic_cast<Number *>(dataTypes[2]->getObject());
    result = PolynomialSubtraction::run(*polynomialA, *polynomialB, *module);
    return &result;
}

FieldPolynomialSubtractionAlgorithm::FieldPolynomialSubtractionAlgorithm() {
    dataTypes = {
            std::make_shared<FieldPolynomialInputComponent>("PolynomialA"),
            std::make_shared<FieldPolynomialInputComponent>("PolynomialB"),
            std::make_shared<NumberInputComponent>("Module")
    };
}