//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/RingPolynomialAdditionAlgorithm.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"
#include "algorithms/PolynomialAddition.h"
#include "GUI/inputComponents/RingPolynomialInputComponent.h"

std::string RingPolynomialAdditionAlgorithm::getName() const {
    return "Ring polynomial addition";
}

Object *RingPolynomialAdditionAlgorithm::run() {
    RingPolynomial *polynomialA = dynamic_cast<RingPolynomial *>(dataTypes[0]->getObject());
    RingPolynomial *polynomialB = dynamic_cast<RingPolynomial *>(dataTypes[1]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[2]->getObject())->get();
    result = PolynomialAddition::run<RingPolynomial>(*polynomialA, *polynomialB, module);
    return &result;
}

RingPolynomialAdditionAlgorithm::RingPolynomialAdditionAlgorithm() {
    dataTypes = {
            std::make_shared<RingPolynomialInputComponent>("PolynomialA"),
            std::make_shared<RingPolynomialInputComponent>("PolynomialB"),
            std::make_shared<IntInputComponent>("Module")
    };
}