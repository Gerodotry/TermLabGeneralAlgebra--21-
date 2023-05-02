//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Algorithms/VectorMultiplicationAlgorithm.h"
#include "utils/Vector.h"
#include "GUI/InputComponents/VectorInputComponent.h"
#include "utils/Float.h"
#include "algorithms/VectorMultiplication.h"

std::string VectorMultiplicationAlgorithm::getName() const {
    return "Vector multiplication";
}

const std::vector<std::shared_ptr<InputComponent>>& VectorMultiplicationAlgorithm::getTypes() const {
    return dataTypes;
}

Object* VectorMultiplicationAlgorithm::run() {
    Vector3D* vectorA = dynamic_cast<Vector3D*>(dataTypes[0]->getObject());
    Vector3D* vectorB = dynamic_cast<Vector3D*>(dataTypes[1]->getObject());
    result = Float(VectorMultiplication::run(*vectorA, *vectorB));
    return &result;
}

VectorMultiplicationAlgorithm::VectorMultiplicationAlgorithm() {
    dataTypes = {std::make_shared<VectorInputComponent>("VectorA"), std::make_shared<VectorInputComponent>("VectorB")};
}
