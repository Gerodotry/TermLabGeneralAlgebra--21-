#include "algorithms/IsGroupGenerator.h"

bool IsGroupGenerator::run(Number a, const std::set<Number>& field_group, Number modulo) {
    if (a.isZero()) {
        throw std::invalid_argument("Zero can't be a generator");
    }
    if (!modulo.isZero()) {
        a.toField(modulo);
    }
    return isGenerator(a, field_group, modulo);
}

bool IsGroupGenerator::isGenerator(const Number& a, const std::set<Number>& field_group, const Number& modulo) {
    std::set<Number> generated_group;
    generated_group.insert(a);
    Number product = a;
    while (generated_group.size() < field_group.size()) {
        product = NumberMultiplication::run(product, a, modulo);
        if (product == a) {
            break;
        }
        generated_group.insert(product);
    }
    return generated_group == field_group;
}
