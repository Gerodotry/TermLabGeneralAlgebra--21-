//
// Created by Dklishch on 3/26/2023.
//

#include "utils/Int.h"

Int::Int(int value): value(value) {
}

std::string Int::toString() const {
    return std::to_string(value);
}

int Int::get() const {
    return value;
}

int *Int::getPointer() {
    return &value;
}
