//
// Created by Dklishch on 5/8/2023.
//

#include "GUI/algorithms/MillerRabinTestAlgorithm.h"
#include "utils/BigInt.h"
#include "utils/Int.h"
#include "algorithms/MillerRabinTest.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "GUI/inputComponents/BigIntInputComponent.h"


std::string MillerRabinTestAlgorithm::getName() const {
    return "Miller-Rabin test";
}

Object *MillerRabinTestAlgorithm::run() {
    BigInt* number = dynamic_cast<BigInt *>(dataTypes[0]->getObject());
    int iterationsNumber = dynamic_cast<Int *>(dataTypes[1]->getObject())->get();
    result = MillerRabinTest::run(*number, iterationsNumber);
    return &result;
}

MillerRabinTestAlgorithm::MillerRabinTestAlgorithm() {
    dataTypes = {
            std::make_shared<BigIntInputComponent>("Number"),
            std::make_shared<IntInputComponent>("Iterations number")
    };
}