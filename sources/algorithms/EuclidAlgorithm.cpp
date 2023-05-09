//
// Created by Dklishch on 5/9/2023.
//

#include "GUI/algorithms/EuclidAlgorithm.h"
#include "utils/Int.h"
#include "algorithms/Euclid.h"
#include "GUI/inputComponents/FieldPolynomialInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"


std::string EuclidAlgorithm::getName() const {
    return "Euclid";
}

Object *EuclidAlgorithm::run() {
    FieldPolynomial *polynomialA = dynamic_cast<FieldPolynomial *>(dataTypes[0]->getObject());
    FieldPolynomial *polynomialB = dynamic_cast<FieldPolynomial *>(dataTypes[1]->getObject());
    int module = dynamic_cast<Int *>(dataTypes[2]->getObject())->get();
    result.a = Euclid::run(*polynomialA, *polynomialB, result.a, result.b, module);
    return &result;
}

EuclidAlgorithm::EuclidAlgorithm() {
    dataTypes = {
            std::make_shared<FieldPolynomialInputComponent>("PolynomialA"),
            std::make_shared<FieldPolynomialInputComponent>("PolynomialB"),
            std::make_shared<IntInputComponent>("Module")
    };
}