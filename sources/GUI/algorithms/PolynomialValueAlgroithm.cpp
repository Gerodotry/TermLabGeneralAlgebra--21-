//
// Created by Dklishch on 5/15/2023.
//

#include "GUI/algorithms/PolynomialValueAlgorithm.h"
#include "GUI/inputComponents/RingPolynomialInputComponent.h"
#include "algorithms/PolynomialValue.h"
#include "GUI/inputComponents/NumberInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"

std::string PolynomialValueAlgorithm::getName() const {
    return "Ring polynomial value";
}

Object *PolynomialValueAlgorithm::run() {
    RingPolynomial *polynomial = dynamic_cast<RingPolynomial *>(dataTypes[0]->getObject());
    Number *number = dynamic_cast<Number *>(dataTypes[1]->getObject());
    Number *module = dynamic_cast<Number *>(dataTypes[2]->getObject());
    result = PolynomialValue::run(*polynomial, *number, *module);
    return &result;
}

PolynomialValueAlgorithm::PolynomialValueAlgorithm() {
    dataTypes = {
            std::make_shared<RingPolynomialInputComponent>("Polynomial"),
            std::make_shared<NumberInputComponent>("Point"),
            std::make_shared<NumberInputComponent>("Module")
    };
}