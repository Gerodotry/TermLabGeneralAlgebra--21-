#ifndef LAB_ISGROUPGENERATOR_H
#define LAB_ISGROUPGENERATOR_H

#include <stdexcept>
#include <set>
#include "utils/Number.h"
#include "NumberMultiplication.h"

class IsGroupGenerator {
public:
    static bool run(Number a, const std::set<Number>& field_group, Number modulo);

private:
    static bool isGenerator(const Number& a, const std::set<Number>& field_group, const Number& modulo);
};



#endif //LAB_ISGROUPGENERATOR_H
