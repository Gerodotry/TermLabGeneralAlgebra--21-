//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/FieldPolynomialFastPoweringAlgorithm.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"
#include "GUI/inputComponents/FieldPolynomialInputComponent.h"
#include "utils/FieldPolynomial.h"
#include "algorithms/PolynomialFastPowering.h"

std::string FieldPolynomialFastPoweringAlgorithm::getName() const {
    return "Field polynomial fast powering";
}

Object *FieldPolynomialFastPoweringAlgorithm::run() {
    FieldPolynomial *polynomial = dynamic_cast<FieldPolynomial *>(dataTypes[0]->getObject());
    int power = dynamic_cast<Int *>(dataTypes[1]->getObject())->get();
    int module = dynamic_cast<Int *>(dataTypes[2]->getObject())->get();
    result = PolynomialFastPowering::run<FieldPolynomial>(*polynomial, power, module);
    return &result;
}

FieldPolynomialFastPoweringAlgorithm::FieldPolynomialFastPoweringAlgorithm() {
    dataTypes = {
            std::make_shared<FieldPolynomialInputComponent>("Polynomial"),
            std::make_shared<IntInputComponent>("Power"),
            std::make_shared<IntInputComponent>("Module")
    };
}