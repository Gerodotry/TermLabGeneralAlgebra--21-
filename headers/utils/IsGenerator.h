//
// Created by Dklishch on 6/11/2023.
//

#ifndef LAB_ISGENERATOR_H
#define LAB_ISGENERATOR_H


#include "Bool.h"
#include "Int.h"

class IsGenerator: public Object {
public:
    Bool isGenerator;
    Int order;

    IsGenerator() {}
    IsGenerator(bool inIsGenerator, int inOrder): isGenerator(inIsGenerator), order(inOrder) {

    }

    std::string toString() override;
};


#endif //LAB_ISGENERATOR_H
