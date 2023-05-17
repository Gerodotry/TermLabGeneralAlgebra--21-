//
// Created by Dklishch on 5/8/2023.
//

#include "GUI/algorithms/DivisionAlgorithm.h"
#include "algorithms/Division.h"
#include "utils/Int.h"
#include "GUI/inputComponents/RawPolynomialInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"

std::string DivisionAlgorithm::getName() const {
    return "Ring polynomial divison";
}

Object *DivisionAlgorithm::run() {
    RawPolynomial *polynomialA = dynamic_cast<RawPolynomial *>(dataTypes[0]->getObject());
    RawPolynomial *polynomialB = dynamic_cast<RawPolynomial *>(dataTypes[1]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[2]->getObject())->get();

    std::vector<int> coefficients = Division::run(polynomialA->coefficients, polynomialB->coefficients, module);
    result = RawPolynomial(coefficients);
    return &result;
}

DivisionAlgorithm::DivisionAlgorithm() {
    dataTypes = {
            std::make_shared<RawPolynomialInputComponent>("PolynomialA"),
            std::make_shared<RawPolynomialInputComponent>("PolynomialB"),
            std::make_shared<IntInputComponent>("Module")
    };
}