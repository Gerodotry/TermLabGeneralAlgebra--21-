//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/FieldPolynomialAdditionAlgorithm.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"
#include "algorithms/PolynomialAddition.h"
#include "GUI/inputComponents/FieldPolynomialInputComponent.h"
#include "utils/FieldPolynomial.h"
#include "GUI/inputComponents/NumberInputComponent.h"

std::string FieldPolynomialAdditionAlgorithm::getName() const {
    return "Field polynomial addition";
}

Object *FieldPolynomialAdditionAlgorithm::run() {
    FieldPolynomial *polynomialA = dynamic_cast<FieldPolynomial *>(dataTypes[0]->getObject());
    FieldPolynomial *polynomialB = dynamic_cast<FieldPolynomial *>(dataTypes[1]->getObject());
    Number *module = dynamic_cast<Number *>(dataTypes[2]->getObject());
    result = PolynomialAddition::run<FieldPolynomial>(*polynomialA, *polynomialB, *module);
    return &result;
}

FieldPolynomialAdditionAlgorithm::FieldPolynomialAdditionAlgorithm() {
    dataTypes = {
            std::make_shared<FieldPolynomialInputComponent>("PolynomialA"),
            std::make_shared<FieldPolynomialInputComponent>("PolynomialB"),
            std::make_shared<NumberInputComponent>("Module")
    };
}