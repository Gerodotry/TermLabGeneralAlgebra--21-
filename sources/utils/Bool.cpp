//
// Created by Dklishch on 5/8/2023.
//

#include "utils/Bool.h"

Bool::Bool(bool value): value(value) {

}

std::string Bool::toString() {
    return value ? "True" : "False";
}

bool Bool::get() const {
    return value;
}

bool* Bool::getPointer() {
    return &value;
}