//
// Created by Dklishch on 3/26/2023.
//

#ifndef MAIN_CPP_INT_H
#define MAIN_CPP_INT_H


#include "Object.h"

class Int : public Object {
public:
    Int(int value);

    std::string toString() const override;

    int get() const;
private:
    int value;
};


#endif //MAIN_CPP_INT_H
