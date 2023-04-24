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

std::vector<InputComponent*> VectorMultiplicationAlgorithm::getTypes() const {
    return dataTypes;
}

Object* VectorMultiplicationAlgorithm::run() {
    Vector3D* vectorA = dynamic_cast<Vector3D*>(dataTypes[0]->getObject());
    Vector3D* vectorB = dynamic_cast<Vector3D*>(dataTypes[1]->getObject());
    float result = VectorMultiplication::run(*vectorA, *vectorB);
    return new Float(result);
}

VectorMultiplicationAlgorithm::VectorMultiplicationAlgorithm() {
    dataTypes = {new VectorInputComponent("VectorA"), new VectorInputComponent("VectorB")};
}

VectorMultiplicationAlgorithm::~VectorMultiplicationAlgorithm() {
    for (auto type: dataTypes) {
        delete type;
    }
    dataTypes.clear();
}
