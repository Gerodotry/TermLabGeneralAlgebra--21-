//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/RingPolynomialFastPoweringAlgorithm.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "utils/Int.h"
#include "algorithms/PolynomialAddition.h"
#include "utils/FieldPolynomial.h"
#include "algorithms/PolynomialFastPowering.h"
#include "GUI/inputComponents/RingPolynomialInputComponent.h"
#include "GUI/inputComponents/NumberInputComponent.h"

std::string RingPolynomialFastPoweringAlgorithm::getName() const {
    return "Ring polynomial fast powering";
}

Object *RingPolynomialFastPoweringAlgorithm::run() {
    RingPolynomial *polynomial = dynamic_cast<RingPolynomial *>(dataTypes[0]->getObject());
    int power = dynamic_cast<Int *>(dataTypes[1]->getObject())->get();
    Number *module = dynamic_cast<Number *>(dataTypes[2]->getObject());
    result = PolynomialFastPowering::run<RingPolynomial>(*polynomial, power, *module);
    return &result;
}

RingPolynomialFastPoweringAlgorithm::RingPolynomialFastPoweringAlgorithm() {
    dataTypes = {
            std::make_shared<RingPolynomialInputComponent>("Polynomial"),
            std::make_shared<IntInputComponent>("Power"),
            std::make_shared<NumberInputComponent>("Module")
    };
}