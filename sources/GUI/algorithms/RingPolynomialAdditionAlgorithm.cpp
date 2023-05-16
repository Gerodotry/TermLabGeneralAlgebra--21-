//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/RingPolynomialAdditionAlgorithm.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"
#include "algorithms/PolynomialAddition.h"
#include "GUI/inputComponents/RingPolynomialInputComponent.h"
#include "GUI/inputComponents/NumberInputComponent.h"

std::string RingPolynomialAdditionAlgorithm::getName() const {
    return "Ring polynomial addition";
}

Object *RingPolynomialAdditionAlgorithm::run() {
    RingPolynomial *polynomialA = dynamic_cast<RingPolynomial *>(dataTypes[0]->getObject());
    RingPolynomial *polynomialB = dynamic_cast<RingPolynomial *>(dataTypes[1]->getObject());
    Number* module = dynamic_cast<Number *>(dataTypes[2]->getObject());
    result = PolynomialAddition::run<RingPolynomial>(*polynomialA, *polynomialB, *module);
    return &result;
}

RingPolynomialAdditionAlgorithm::RingPolynomialAdditionAlgorithm() {
    dataTypes = {
            std::make_shared<RingPolynomialInputComponent>("PolynomialA"),
            std::make_shared<RingPolynomialInputComponent>("PolynomialB"),
            std::make_shared<NumberInputComponent>("Module")
    };
}