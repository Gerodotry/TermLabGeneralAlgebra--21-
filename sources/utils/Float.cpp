//
// Created by Dklishch on 3/26/2023.
//

#include "utils/Float.h"

Float::Float(float value): value(value) {
}

std::string Float::toString() const {
    return std::to_string(value);
}
