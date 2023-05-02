//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/PolynomialSubtractionAlgorithm.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"
#include "GUI/inputComponents/PolynomialInputComponent.h"
#include "algorithms/PolynomialSubtraction.h"

std::string PolynomialSubtractionAlgorithm::getName() const {
    return "Polynomial subtraction";
}

Object *PolynomialSubtractionAlgorithm::run() {
    Polynomial *polynomialA = dynamic_cast<Polynomial *>(dataTypes[0]->getObject());
    Polynomial *polynomialB = dynamic_cast<Polynomial *>(dataTypes[1]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[2]->getObject())->get();
    result = PolynomialSubtraction::run(*polynomialA, *polynomialB, module);
    return &result;
}

PolynomialSubtractionAlgorithm::PolynomialSubtractionAlgorithm() {
    dataTypes = {
            std::make_shared<PolynomialInputComponent>("PolynomialA"),
            std::make_shared<PolynomialInputComponent>("PolynomialB"),
            std::make_shared<IntInputComponent>("Module")
    };
}