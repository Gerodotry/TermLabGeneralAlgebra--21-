//
// Created by Dklishch on 6/1/2023.
//

#ifndef LAB_NUMBERSET_H
#define LAB_NUMBERSET_H

#include <set>
#include "Number.h"

class NumberSet: public Object {
public:
    std::set<Number> numbers;
};

#endif //LAB_NUMBERSET_H
