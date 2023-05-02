//
// Created by Dklishch on 3/7/2023.
//

#ifndef LAB_VECTOR_H
#define LAB_VECTOR_H

#include "Object.h"

class Vector3D : public Object {
public:
    float x = 0;
    float y = 0;
    float z = 0;
private:
    std::string name;
};

class Vector2D {
public:
    float x = 0;
    float y = 0;
};

#endif //LAB_VECTOR_H
