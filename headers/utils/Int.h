//
// Created by Dklishch on 3/26/2023.
//

#ifndef MAIN_CPP_INT_H
#define MAIN_CPP_INT_H


#include "Object.h"

class Int : public Object {
public:
    Int(int value = 0);

    std::string toString() override;

    int get() const;

    int* getPointer();
private:
    int value;
};


#endif //MAIN_CPP_INT_H
