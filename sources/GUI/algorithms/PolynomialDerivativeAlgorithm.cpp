//
// Created by Dklishch on 5/15/2023.
//

#include "GUI/algorithms/PolynomialDerivativeAlgorithm.h"
#include "GUI/inputComponents/RingPolynomialInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "algorithms/PolynomialDerivative.h"

std::string PolynomialDerivativeAlgorithm::getName() const {
    return "Ring polynomial derivative";
}

Object *PolynomialDerivativeAlgorithm::run() {
    RingPolynomial *polynomial = dynamic_cast<RingPolynomial *>(dataTypes[0]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[1]->getObject())->get();
    result = PolynomialDerivative::run(*polynomial, module);
    return &result;
}

PolynomialDerivativeAlgorithm::PolynomialDerivativeAlgorithm() {
    dataTypes = {
            std::make_shared<RingPolynomialInputComponent>("Polynomial"),
            std::make_shared<IntInputComponent>("Module")
    };
}