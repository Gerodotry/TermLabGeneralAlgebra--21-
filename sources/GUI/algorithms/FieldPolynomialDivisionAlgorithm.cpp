#include "GUI/algorithms/FieldPolynomialDivisionAlgorithm.h"
#include "utils/Int.h"
#include "algorithms/PolynomialDivision.h"
#include "GUI/inputComponents/FieldPolynomialInputComponent.h"
#include "GUI/inputComponents/IntInputComponent.h"
#include "GUI/inputComponents/NumberInputComponent.h"

std::string FieldPolynomialDivisionAlgorithm::getName() const {
    return "Field polynomial division";
}

Object *FieldPolynomialDivisionAlgorithm::run() {
    FieldPolynomial *dividend = dynamic_cast<FieldPolynomial *>(dataTypes[0]->getObject());
    FieldPolynomial *divisor = dynamic_cast<FieldPolynomial *>(dataTypes[1]->getObject());
    Number *modulo = dynamic_cast<Number *>(dataTypes[2]->getObject());
    result = PolynomialDivision::run(*dividend, *divisor, *modulo);
    return &result;
}

FieldPolynomialDivisionAlgorithm::FieldPolynomialDivisionAlgorithm() {
    dataTypes = {
            std::make_shared<FieldPolynomialInputComponent>("Dividend"),
            std::make_shared<FieldPolynomialInputComponent>("Divisor"),
            std::make_shared<NumberInputComponent>("Modulo")
    };
}
