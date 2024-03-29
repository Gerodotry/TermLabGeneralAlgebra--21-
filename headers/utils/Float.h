//
// Created by Dklishch on 3/26/2023.
//

#ifndef MAIN_CPP_FLOAT_H
#define MAIN_CPP_FLOAT_H


#include "Object.h"

class Float : public Object {
public:
    Float(float value = 0);

    std::string toString() override;
private:
    float value;
};


#endif //MAIN_CPP_FLOAT_H
