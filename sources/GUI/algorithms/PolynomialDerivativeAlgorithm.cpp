//
// Created by Dklishch on 5/15/2023.
//

#include "GUI/algorithms/PolynomialDerivativeAlgorithm.h"
#include "GUI/inputComponents/RingPolynomialInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "algorithms/PolynomialDerivative.h"
#include "GUI/inputComponents/NumberInputComponent.h"

std::string PolynomialDerivativeAlgorithm::getName() const {
    return "Ring polynomial derivative";
}

Object *PolynomialDerivativeAlgorithm::run() {
    RingPolynomial *polynomial = dynamic_cast<RingPolynomial *>(dataTypes[0]->getObject());
    Number *module = dynamic_cast<Number *>(dataTypes[1]->getObject());
    result = PolynomialDerivative::run(*polynomial, *module);
    return &result;
}

PolynomialDerivativeAlgorithm::PolynomialDerivativeAlgorithm() {
    dataTypes = {
            std::make_shared<RingPolynomialInputComponent>("Polynomial"),
            std::make_shared<NumberInputComponent>("Module")
    };
}