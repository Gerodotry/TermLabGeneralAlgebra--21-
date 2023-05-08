//
// Created by Dklishch on 5/8/2023.
//

#include "GUI/algorithms/RemainderAlgorithm.h"
#include "GUI/inputComponents/RawPolynomialInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "algorithms/Remainder.h"

std::string RemainderAlgorithm::getName() const {
    return "Ring polynomial remainder";
}

Object *RemainderAlgorithm::run() {
    RawPolynomial *polynomialA = dynamic_cast<RawPolynomial *>(dataTypes[0]->getObject());
    RawPolynomial *polynomialB = dynamic_cast<RawPolynomial *>(dataTypes[1]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[2]->getObject())->get();
    std::vector<int> coefficients = Remainder::run(polynomialA->coefficients, polynomialB->coefficients, module);
    result = RawPolynomial(coefficients);
    return &result;
}

RemainderAlgorithm::RemainderAlgorithm() {
    dataTypes = {
            std::make_shared<RawPolynomialInputComponent>("PolynomialA"),
            std::make_shared<RawPolynomialInputComponent>("PolynomialB"),
            std::make_shared<IntInputComponent>("Module")
    };
}