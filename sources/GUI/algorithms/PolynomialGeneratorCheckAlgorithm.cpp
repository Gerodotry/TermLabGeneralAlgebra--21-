//
// Created by Dklishch on 5/16/2023.
//

#include "GUI/algorithms/PolynomialGeneratorCheckAlgorithm.h"
#include "utils/RawPolynomial.h"
#include "GUI/inputComponents/RawPolynomialInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "algorithms/PolynomialGeneratorCheck.h"

std::string PolynomialGeneratorCheckAlgorithm::getName() const {
    return "Ring polynomial generator check";
}

Object *PolynomialGeneratorCheckAlgorithm::run() {
    RawPolynomial *polynomial = dynamic_cast<RawPolynomial*>(dataTypes[0]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[1]->getObject())->get();
    int order;
    bool isGenerator = PolynomialGeneratorCheck::is_generator(polynomial->_degrees, module, order);
    result = { isGenerator, order };
    return &result;
}

PolynomialGeneratorCheckAlgorithm::PolynomialGeneratorCheckAlgorithm() {
    dataTypes = {
            std::make_shared<RawPolynomialInputComponent>("Polynomial"),
            std::make_shared<IntInputComponent>("Module")
    };
}