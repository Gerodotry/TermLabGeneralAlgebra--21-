//
// Created by Dklishch on 6/1/2023.
//

#include "utils/Long.h"

Long::Long(long long value): value(value) {
}

std::string Long::toString() {
    return std::to_string(value);
}

long long Long::get() const {
    return value;
}

long long *Long::getPointer() {
    return &value;
}
