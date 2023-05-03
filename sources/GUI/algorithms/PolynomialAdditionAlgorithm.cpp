//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/PolynomialAdditionAlgorithm.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"
#include "algorithms/RingPolynomialAddition.h"
#include "GUI/inputComponents/PolynomialInputComponent.h"

std::string PolynomialAdditionAlgorithm::getName() const {
    return "RingPolynomial addition";
}

Object *PolynomialAdditionAlgorithm::run() {
    RingPolynomial *polynomialA = dynamic_cast<RingPolynomial *>(dataTypes[0]->getObject());
    RingPolynomial *polynomialB = dynamic_cast<RingPolynomial *>(dataTypes[1]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[2]->getObject())->get();
    result = RingPolynomialAddition::run(*polynomialA, *polynomialB, module);
    return &result;
}

PolynomialAdditionAlgorithm::PolynomialAdditionAlgorithm() {
    dataTypes = {
            std::make_shared<PolynomialInputComponent>("PolynomialA"),
            std::make_shared<PolynomialInputComponent>("PolynomialB"),
            std::make_shared<IntInputComponent>("Module")
    };
}