//
// Created by Dklishch on 5/8/2023.
//

#include "GUI/algorithms/GcdAlgorithm.h"
#include "utils/Int.h"
#include "algorithms/Gcd.h"
#include "GUI/inputComponents/RawPolynomialInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"

std::string GcdAlgorithm::getName() const {
    return "Ring polynomial gcd";
}

Object *GcdAlgorithm::run() {
    RawPolynomial *polynomialA = dynamic_cast<RawPolynomial *>(dataTypes[0]->getObject());
    RawPolynomial *polynomialB = dynamic_cast<RawPolynomial *>(dataTypes[1]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[2]->getObject())->get();
    std::vector<int> coefficients = Gcd::run(polynomialA->coefficients, polynomialB->coefficients, module);
    result = RawPolynomial(coefficients);
    return &result;
}

GcdAlgorithm::GcdAlgorithm() {
    dataTypes = {
            std::make_shared<RawPolynomialInputComponent>("PolynomialA"),
            std::make_shared<RawPolynomialInputComponent>("PolynomialB"),
            std::make_shared<IntInputComponent>("Module")
    };
}