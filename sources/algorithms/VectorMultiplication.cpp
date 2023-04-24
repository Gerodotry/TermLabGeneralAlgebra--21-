//
// Created by Dklishch on 3/7/2023.
//

#include "algorithms/VectorMultiplication.h"

float VectorMultiplication::run(const Vector3D &vectorA, Vector3D &vectorB) {
    return vectorA.x * vectorB.x + vectorA.y * vectorB.y + vectorA.z * vectorB.z;
}