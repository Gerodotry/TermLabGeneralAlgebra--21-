//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/RingPolynomialSubtractionAlgorithm.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"
#include "GUI/inputComponents/FieldPolynomialInputComponent.h"
#include "algorithms/PolynomialSubtraction.h"
#include "GUI/inputComponents/RingPolynomialInputComponent.h"

std::string RingPolynomialSubtractionAlgorithm::getName() const {
    return "Ring polynomial subtraction";
}

Object *RingPolynomialSubtractionAlgorithm::run() {
    RingPolynomial *polynomialA = dynamic_cast<RingPolynomial *>(dataTypes[0]->getObject());
    RingPolynomial *polynomialB = dynamic_cast<RingPolynomial *>(dataTypes[1]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[2]->getObject())->get();
    result = PolynomialSubtraction::run(*polynomialA, *polynomialB, module);
    return &result;
}

RingPolynomialSubtractionAlgorithm::RingPolynomialSubtractionAlgorithm() {
    dataTypes = {
            std::make_shared<RingPolynomialInputComponent>("PolynomialA"),
            std::make_shared<RingPolynomialInputComponent>("PolynomialB"),
            std::make_shared<IntInputComponent>("Module")
    };
}